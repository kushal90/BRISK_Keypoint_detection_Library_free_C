#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include<stdbool.h>
#include<assert.h>
#include<xmmintrin.h>
#include<tmmintrin.h>
//#include "agast.c"
#include "fast_9.c"
//#include"briskfxn.c"
//#include "nonmax.c"
#include <stdint.h>
//struct image {
//    int **image;
//    int    height;
//    int    width;
//};
typedef struct image image;
typedef unsigned char byte;
typedef unsigned char uchar;
void load_image(char *, int *, int *);
void write_image(image *, char *);
void reduce(image *, image *);
void gaussian(image *, image *);
//void halfsample(image *, image *);
//static inline void new_everything();
void everything();
void latest();
void getKeypoints();
void substract(image *, image *, image *);
void allocate_my_images();
void free_my_images();
void transformImageToByte(image *, int);
bool isMax2D(const , const int , const int , int **scores);
//static inline void reduce2_3_paper(image *, image*);
///////////////////////////////////GLOBALS//////////////////////////////////////
image original,dneg,d1,d2,d3;
image images[4][5];
image substracted_images[4][4];
image pyramid[8];
xy* corners;
int num_corners;
int **scores;
int *** scoremat;
int ** scoremat5;
int layers = 8;
float oscale[8];
float offset[8];
float scale[8];
byte *img_char[8];
int height, width;
void imgcharmatrix()
{
	int i;
	for (i=0; i<8;i++)
	{
		int m = pyramid[i].width*pyramid[i].height;
			
		// Allocate memory for image as a 1D character array.
		img_char[i] = malloc( m * sizeof(byte*) );
			
		//2D array to 1D.
		transformImageToByte(&pyramid[i], i);
	}
}
void scaleof(){
			int i;
			oscale[0] = 1;
			oscale[1] = 1.5;
			oscale[2] = 2;
			oscale[3] = 3;
			oscale[4] = 4;
			oscale[5] = 6;
			oscale[6] = 8;
			oscale[7] = 12;
}
void my_offsetof(){
			int i;
			oscale[0] = 1;
			oscale[1] = 1.5;
			oscale[2] = 2;
			oscale[3] = 3;
			oscale[4] = 4;
			oscale[5] = 6;
			oscale[6] = 8;
			oscale[7] = 12;
			for (i=0; i < 8; i++)
			{
					offset[i] = 0.5*oscale[i]-0.5;
			}
}
void transformImageToByte(image *image, int p)
{
	int i;
	int j;
	
	for(i = 0; i<image->height; i++)
	{
		for(j = 0; j< image->width; j++)
		{
			
//			printf("\ni = %d and j = %d start\n",i,j);
//			int m = i*image->width+j;
//			printf("\nindex= %d\n",m);
//			printf("\nim: %d",image->image[i][j]);
			byte newValue = image->image[i][j];
//			printf("\ni = %d and j = %d end\n",i,j);
		*(img_char[p]+i*image->width+j) = newValue;
//			printf("Hello");
		}
	}
}
int main()
{
    printf("\nStart\n");
	load_image("C:\\...\\Images\\img1.pgm", &height, &width);
	printf("\nImage Loaded\n");
//	new_everything();
	everything();
//	latest();
	getKeypoints();
	system("pause");
}
void load_image(char *filename, int *height, int *width) 
{
    FILE *input, *out;
    char c;
    char comment[50];
    int x, y, i;
    
    input = fopen(filename, "rb");
    out = fopen("test.pgm", "wb");
    
    c = getc(input); // 'P'
    c = getc(input); // '5'
    
    fscanf(input, " "); // '\n'
    c = fgetc(input); 
    
    while(c == '#') 
    {
        fgets(comment,40,input);
        while(comment[strlen(comment)-1]!='\n') 
        {
            fgets(comment,40,input);
        }
        fscanf(input," ");
        c = fgetc(input);
    }
    
    ungetc(c,input);
    fscanf(input," %d %d ", &original.width, &original.height);
    c = fgetc(input);
    while(c == '#') 
    {
        fgets(comment,40,input);
        while(comment[strlen(comment)-1]!='\n') 
        {
            fgets(comment,40,input);
        }
        fscanf(input," ");
        c = fgetc(input);
    }
    
    ungetc(c,input);
    fscanf(input," %d",&x);
    fgetc(input);
//    allocate_images();
    allocate_my_images();
    fprintf(out, "P5\n%d %d\n255\n", original.width, original.height);
    
    for(x = 0; x < original.height; x++) 
    {
        for(y = 0; y < original.width; y++) 
        {
            fscanf(input,"%c", &original.image[x][y]);
            fprintf(out, "%c", original.image[x][y]);       
        }
    }
             
    fclose(input);
    fclose(out);
}
void write_image(image *img, char *filename) 
{
    FILE *output, *test;
    int x,y;
    
    output = fopen(filename,"wb");
    test = fopen("test.txt", "w");
        printf("\nimg(width, height) = (%d, %d)\n", img -> width, img -> height);
        
        fprintf(test, "file = %s\n", filename);
        
        fprintf(output,"P5\n%d %d\n255\n", img -> width, img -> height);
        
        for(x = 0; x < img -> height; x++) 
        {
            for(y = 0; y < img -> width; y++) 
            {
                fprintf(output, "%c", img -> image[x][y]);
                if(img -> image[x][y] == 0) fprintf(test, "%d, %d\n", y, x);
            }
        }
    fclose(output);
    fclose(test);
}
void reduce(image *orig, image *reduced)
{
    int j;
    double sum;
    int x, y;
	reduced -> height = orig -> height/2;
    reduced -> width = orig -> width/2;
    
    int x0 = 0;
	int y0 = 0;
    
    for(x = 0; x < orig -> height; x+=2)
    {
        for(y = 0; y < orig -> width; y+=2)
        {
            sum = 0;
            sum+=orig -> image[x][y];
            sum+=orig -> image[x+1][y];
            sum+=orig -> image[x][y+1];
            sum+=orig -> image[x+1][y+1];
        	
            reduced -> image[x0][y0] = (int)(sum/4);
            y0++;
        }
        y0 = 0;
        x0++;
    }
}
void reduce2_3(image *orig, image *reduced)
{
    int j;
    double sum;
    int x, y;
	reduced -> height = (int)((float)(orig -> height)/((float)3/2));
    reduced -> width = (int)((float)(orig -> width)/((float)3/2));
    int x0 = 0;
	int y0 = 0;
	int hr = height%3;
	int wr = width%3;
//    if (height%3 == 0 && width%3 == 0)
//    {
    		for(x = 0; x < orig -> height - hr-2; x+=3)
    		{
        		for(y = 0; y < orig -> width - wr ; y+=3)
        		{
			            reduced -> image[x0][y0] = (int)((4*orig -> image[x][y] + 2*orig -> image[x+1][y] + 2*orig -> image[x][y+1] + orig -> image[x+1][y+1])/9);
			            reduced -> image[x0][y0+1] = (int)((4*orig -> image[x][y+2] + 2*orig -> image[x+1][y+2] + 2*orig -> image[x][y+1] + orig -> image[x+1][y+1])/9);
			            reduced -> image[x0+1][y0] = (int)((4*orig -> image[x+2][y] + 2*orig -> image[x+1][y] + 2*orig -> image[x+2][y+1] + orig -> image[x+1][y+1])/9);
			            reduced -> image[x0+1][y0+1] = (int)((4*orig -> image[x+2][y+2] + 2*orig -> image[x+1][y+2] + 2*orig -> image[x+2][y+1] + orig -> image[x+1][y+1])/9);
			            y0+=2;
//			            printf("%d\n", y);
        		}
        	
        		
//        		printf("%d %d %d\n", x, x0, y0);
        			y0 = 0;
        		x0+=2;
    		}
//	}
}
void everything()
{
	//all images 4 rows 5 columns (first column and first row is original and other rows of first column are down sampled images) other columns are blurred images
	
//	images[0][0] = original;
	pyramid[0] = original;
//	write_image(&original, "C:\\Users\\kkumar\\Documents\\Oulu\\Kushal\\Output\\original.pgm");
//	write_image(&images[0][0], "C:\\Users\\Kushal\\Documents\\Oulu\\Kushal\\Output\\00original.pgm");
	write_image(&pyramid[0], "C:\\Users\\kkumar\\Documents\\Oulu\\Kushal\\Output\\pyramid0.pgm");
//	printf("fdsf");
	//Big for 	
	int i;
	
	for (i = 0; i < 8; i+=2)
	{
		if (i==0)
		{
		reduce2_3(&pyramid[i], &pyramid[i+1]);
		
		reduce(&pyramid[i], &pyramid[i+2]);
		
//		gaussian(&pyramid[i+1], &pyramid[i+1]);
//		gaussian(&pyramid[i+2], &pyramid[i+2]);
		}
		else
		{
			reduce(&pyramid[i-1], &pyramid[i+1]);
			if(i+2<8)
				reduce(&pyramid[i], &pyramid[i+2]);
//			if (i%2 == 0 && i < 6 && i > 0)
//				{
//					reduce(&pyramid[i], &pyramid[i+2]);
//					
//					reduce(&pyramid[i-1], &pyramid[i+1]);
////					printf("hello");
////					gaussian(&pyramid[i+1], &pyramid[i+1]);
////					gaussian(&pyramid[i+2], &pyramid[i+2]);
//				}
//			else
//				{
//					reduce(&pyramid[i-1], &pyramid[i+1]);
//					
////					gaussian(&pyramid[i+1], &pyramid[i+1]);
//				}
//			if (i%2 == 0 && i < 6 && i > 0)
//
//				{
//
//					reduce(&pyramid[i], &pyramid[i+2]);
//
//					
//
//					reduce(&pyramid[i-1], &pyramid[i+1]);
//
////					printf("hello");
//
////					gaussian(&pyramid[i+1], &pyramid[i+1]);
//
////					gaussian(&pyramid[i+2], &pyramid[i+2]);
//
//				}
//
//			else
//
//				{
//
//					reduce(&pyramid[i-1], &pyramid[i+1]);
//
//					
//
////					gaussian(&pyramid[i+1], &pyramid[i+1]);
//
//				}
			
		}
	}
	
	write_image(&pyramid[1], "C:\\Users\\kkumar\\Documents\\Oulu\\Kushal\\Output\\pyramid1.pgm");
	write_image(&pyramid[2], "C:\\Users\\kkumar\\Documents\\Oulu\\Kushal\\Output\\pyramid2.pgm");
	write_image(&pyramid[3], "C:\\Users\\kkumar\\Documents\\Oulu\\Kushal\\Output\\pyramid3.pgm");
	write_image(&pyramid[4], "C:\\Users\\kkumar\\Documents\\Oulu\\Kushal\\Output\\pyramid4.pgm");
	write_image(&pyramid[5], "C:\\Users\\kkumar\\Documents\\Oulu\\Kushal\\Output\\pyramid5.pgm");
	write_image(&pyramid[6], "C:\\Users\\kkumar\\Documents\\Oulu\\Kushal\\Output\\pyramid6.pgm");
	write_image(&pyramid[7], "C:\\Users\\kkumar\\Documents\\Oulu\\Kushal\\Output\\pyramid7.pgm");
}
void allocate_my_images()
{
//    int a, b, c, d, e, f, g, h;
    int i;
    
    
    
      
//	dneg.image = malloc( original.height * sizeof(int*) );
//	d1.image = malloc( original.height * sizeof(int*) );
//	d2.image = malloc( original.height * sizeof(int*) );
//	d3.image = malloc( original.height * sizeof(int*) );
//    int k;
//	int m;
	int j;
	
	original.image = malloc( original.height * sizeof(int*) );
	
	for (i = 0; i<8; i++)
	{
		pyramid[i].image = malloc( original.height * sizeof(int*) );
	}
	
	for(i = 0; i < original.height; i++)
    {
    	original.image[i] = calloc( original.width , sizeof(int) );
    	for (j = 0; j < 8; j++)
    	{
        pyramid[j].image[i] = calloc( original.width , sizeof(int) );
    	}
    }
}
void free_my_images()
{
    int i;
	int j;
    
    for(i = 0; i < original.height; i++)
    {
    	free(original.image[i]);
    	for (j = 0; j < 8; j++)
    	{
        free(pyramid[j].image[i]);
    	}
    }
    
    free(original.image);
    
    for (j = 0; j < 8; j++)
    	{
        free(pyramid[j].image);
    	}
    
}
void substract(image *first_image, image *second_image, image *result_image)
{
	result_image -> height = second_image -> height;
    result_image -> width = second_image -> width;
    int x;
    int y;
	for(x = 0; x < second_image -> height; x++) 
    {
        for(y = 0; y < second_image -> width; y++) 
        {
            result_image -> image[x][y] = second_image -> image[x][y] - first_image -> image[x][y];
        }
    }
}
uint8_t score(int p, int x, int y, int threshold)
{	
	height = pyramid[p].height;
	width = pyramid[p].width;
	
	if(x<3||y<3) return 0;
	if(x>=height-3||y>=width-3) return 0;
	
	if(scoremat[p][x][y]>2) 
	{ 
		return scoremat[p][x][y];
	}
	
	int pixel[16];
//	make_offsets(pixel, width);
	
	scoremat[p][x][y] = fast9_corner_score(img_char[p] + y + x*width, pixel, threshold-1, width);
	
	if (scoremat[p][x][y] < threshold) scoremat[p][x][y] = 0;
	return scoremat[p][x][y];
}
uint8_t getAgastScore(int p, int x, int y, int threshold)
{	
	height = pyramid[p].height;
	width = pyramid[p].width;
	
	if(x<3||y<3) return 0;
	if(x>=height-3||y>=width-3) return 0;
	
	if(scoremat[p][x][y]>2) 
	{ 
		return scoremat[p][x][y];
	}
	
	int pixel[16];
//	make_offsets(pixel, width);
	
	scoremat[p][x][y] = fast9_corner_score(img_char[p] + y + x*width, pixel, threshold-1, width);
	
	if (scoremat[p][x][y] < threshold) scoremat[p][x][y] = 0;
	return scoremat[p][x][y];
//	printf("%d", scoremat[p][x][y]);
}
uint8_t getAgastScore_5_8(int x, int y, int threshold)
{	
	height = pyramid[0].height;
	width = pyramid[0].width;
	
	
	if(x<2||y<2) return 0;
	if(x>=height-2||y>=width-2) return 0;
	
	
	int pixel[8];
	make_offsets5(pixel, width);
	
	scoremat5[x][y] = fast5_corner_score(img_char[0] + y + x*width, pixel, threshold-1);
	
	if (scoremat5[x][y] < threshold) scoremat5[x][y] = 0;
	return scoremat5[x][y];
}
uint8_t value(int p, float xf, float yf, float scale)
{
	// get the position
	const int x = floor(xf);
	const int y = floor(yf);
	int imagecols=pyramid[p].width;
	
//	byte *img_char;
//	transformImageToByte(&pyramid[p], img_char);
	// get the sigma_half:
	const float sigma_half=scale/2;
	const float area=4.0*sigma_half*sigma_half;
	// calculate output:
	int ret_val;
	if(sigma_half<0.5){
		//interpolation multipliers:
		const int r_x=(xf-x)*1024;
		const int r_y=(yf-y)*1024;
		const int r_x_1=(1024-r_x);
		const int r_y_1=(1024-r_y);
		uchar* ptr=(uchar*)(*scoremat[p]+y+x*imagecols);
//		uchar* ptr=image.data+x+y*imagecols;
		// just interpolate:
		ret_val=(r_x_1*r_y_1*(int)(*ptr));
		ptr++;
		ret_val+=(r_x*r_y_1*(int)(*ptr));
		ptr+=imagecols;
		ret_val+=(r_x*r_y*(int)(*ptr));
		ptr--;
		ret_val+=(r_x_1*r_y*(int)(*ptr));
		return 0xFF&((ret_val+512)/1024/1024);
	}
	// this is the standard case (simple, not speed optimized yet):
	// scaling:
	const int scaling = 4194304.0/area;
	const int scaling2=(float)(scaling)*area/1024.0;
	// calculate borders
	const float x_1=xf-sigma_half;
	const float x1=xf+sigma_half;
	const float y_1=yf-sigma_half;
	const float y1=yf+sigma_half;
	const int x_left=(int)(x_1+0.5);
	const int y_top=(int)(y_1+0.5);
	const int x_right=(int)(x1+0.5);
	const int y_bottom=(int)(y1+0.5);
	// overlap area - multiplication factors:
	const float r_x_1=(float)(x_left)-x_1+0.5;
	const float r_y_1=(float)(y_top)-y_1+0.5;
	const float r_x1=x1-(float)(x_right)+0.5;
	const float r_y1=y1-(float)(y_bottom)+0.5;
	const int dx=x_right-x_left-1;
	const int dy=y_bottom-y_top-1;
	const int A=(r_x_1*r_y_1)*scaling;
	const int B=(r_x1*r_y_1)*scaling;
	const int C=(r_x1*r_y1)*scaling;
	const int D=(r_x_1*r_y1)*scaling;
	const int r_x_1_i=r_x_1*scaling;
	const int r_y_1_i=r_y_1*scaling;
	const int r_x1_i=r_x1*scaling;
	const int r_y1_i=r_y1*scaling;
	// now the calculation:
	uchar* ptr=(uchar*)(*scoremat[p]+y_top+imagecols*x_left);
	// first row:
	ret_val=A*(int)(*ptr);
	ptr++;
	const uchar* end1 = ptr+dy;
	for(; ptr<end1; ptr++){
		ret_val+=r_x_1_i*(int)(*ptr);
	}
	ret_val+=B*(int)(*ptr);
	// middle ones:
	ptr+=imagecols-dy-1;
	uchar* end_j=ptr+dx*imagecols;
	for(; ptr<end_j; ptr+=imagecols-dy-1){
		ret_val+=r_y_1_i*(int)(*ptr);
		ptr++;
		const uchar* end2 = ptr+dy;
		for(; ptr<end2; ptr++){
			ret_val+=(int)(*ptr)*scaling;
		}
		ret_val+=r_y1_i*(int)(*ptr);
	}
	// last row:
	ret_val+=D*(int)(*ptr);
	ptr++;
	const uchar* end3 = ptr+dy;
	for(; ptr<end3; ptr++){
		ret_val+=r_x1_i*(int)(*ptr);
	}
	ret_val+=C*(int)(*ptr);
	return 0xFF&((ret_val+scaling2/2)/scaling2/1024);
}
uint8_t scoref(int layer, float xf, float yf, int threshold)
{
	int x, y;
	my_offsetof();
	
	if(oscale[layer]<=1.0f)
	{
		const int x=(int)(xf);
		const float rx1=xf-(float)(x);
		const float rx=1.0f-rx1;
		const int y=(int)(yf);
		const float ry1=yf-(float)(y);
		const float ry=1.0f-ry1;
		
		return rx*ry*score(layer, x, y, threshold)+
				rx1*ry*score(layer, x+1, y, threshold)+
				rx*ry1*score(layer, x, y+1, threshold)+
				rx1*ry1*score(layer, x+1, y+1, threshold);
	}	
	
	else{
		
		const float halfscale = oscale[layer]/2.0f;
		
		for(x=(int)(xf-halfscale); x<=(int)(xf+halfscale+1.0f); x++){
			for(y=(int)(yf-halfscale); y<=(int)(yf+halfscale+1.0f); y++){
				
				score(layer, x, y, threshold);
				
			}
		}
		
		return value(layer,xf,yf,oscale[layer]);
	}
}
float subpixel2D(const int s_0_0, const int s_0_1, const int s_0_2,
									const int s_1_0, const int s_1_1, const int s_1_2,
									const int s_2_0, const int s_2_1, const int s_2_2,
									float *delta_x, float *delta_y){
	// the coefficients of the 2d quadratic function least-squares fit:
	register int tmp1 =        s_0_0 + s_0_2 - 2*s_1_1 + s_2_0 + s_2_2;
    register int coeff1 = 3*(tmp1 + s_0_1 - ((s_1_0 + s_1_2)<<1) + s_2_1);
    register int coeff2 = 3*(tmp1 - ((s_0_1+ s_2_1)<<1) + s_1_0 + s_1_2 );
    register int tmp2 =                                  s_0_2 - s_2_0;
    register int tmp3 =                         (s_0_0 + tmp2 - s_2_2);
    register int tmp4 =                                   tmp3 -2*tmp2;
    register int coeff3 =                    -3*(tmp3 + s_0_1 - s_2_1);
	register int coeff4 =                    -3*(tmp4 + s_1_0 - s_1_2);
	register int coeff5 =            (s_0_0 - s_0_2 - s_2_0 + s_2_2)<<2;
	register int coeff6 = -(s_0_0  + s_0_2 - ((s_1_0 + s_0_1 + s_1_2 + s_2_1)<<1) - 5*s_1_1  + s_2_0  + s_2_2)<<1;
	//printf("%d", coeff1);
	// 2nd derivative test:
	register int H_det=4*coeff1*coeff2 - coeff5*coeff5;
	
	//printf("%d mmm",  (int)coeff6/18);
	
	// H_det is 0 in only 7 points.
	if(H_det==0){
		*delta_x=0.0;
		*delta_y=0.0;
//		printf("x: %f - y: %f\n",delta_x, delta_y);
		return ((float) coeff6)/18.0;
	
	}
	if(!(H_det>0&&coeff1<0)){
		// The maximum must be at the one of the 4 patch corners.
		int tmp_max=coeff3+coeff4+coeff5;
		*delta_x=1.0; *delta_y=1.0;
		int tmp = -coeff3+coeff4-coeff5;
		if(tmp>tmp_max){
			tmp_max=tmp;
			*delta_x=-1.0; *delta_y=1.0;
		}
		tmp = coeff3-coeff4-coeff5;
		if(tmp>tmp_max){
			tmp_max=tmp;
			*delta_x=1.0; *delta_y=-1.0;
		}
		tmp = -coeff3-coeff4+coeff5;
		if(tmp>tmp_max){
			tmp_max=tmp;
			*delta_x=-1.0; *delta_y=-1.0;
		}
//		printf("x: %f - y: %f\n",delta_x, delta_y);
		return ((float)tmp_max+coeff1+coeff2+coeff6)/18.0;
		
	}
	
	// this is hopefully the normal outcome of the Hessian test
	*delta_x=((float)(2*coeff2*coeff3 - coeff4*coeff5))/((float)-H_det);
	*delta_y=((float)(2*coeff1*coeff4 - coeff3*coeff5))/((float)(-H_det));
	// TODO: this is not correct, but easy, so perform a real boundary maximum search:
	bool tx=false; bool tx_=false; bool ty=false; bool ty_=false;
	if(*delta_x>1.0) tx=true;
	else if(*delta_x<-1.0) tx_=true;
	if(*delta_y>1.0) ty=true;
	if(*delta_y<-1.0) ty_=true;
	if(tx||tx_||ty||ty_){
		// get two candidates:
		float delta_x1=0.0, delta_x2=0.0, delta_y1=0.0, delta_y2=0.0;
		if(tx) {
			delta_x1=1.0;
			delta_y1=-(float)(coeff4+coeff5)/(float)(2*coeff2);
			if(delta_y1>1.0) delta_y1=1.0; else if (delta_y1<-1.0) delta_y1=-1.0;
		}
		else if(tx_) {
			delta_x1=-1.0;
			delta_y1=-(float)(coeff4-coeff5)/(float)(2*coeff2);
			if(delta_y1>1.0) delta_y1=1.0; else if (delta_y1<-1.0) delta_y1=-1.0;
		}
		if(ty) {
			delta_y2=1.0;
			delta_x2=-(float)(coeff3+coeff5)/(float)(2*coeff1);
			if(delta_x2>1.0) delta_x2=1.0; else if (delta_x2<-1.0) delta_x2=-1.0;
		}
		else if(ty_) {
			delta_y2=-1.0;
			delta_x2=-(float)(coeff3-coeff5)/(float)(2*coeff1);
			if(delta_x2>1.0) delta_x2=1.0; else if (delta_x2<-1.0) delta_x2=-1.0;
		}
		// insert both options for evaluation which to pick
		float max1, max2;
		 max1 = (coeff1*delta_x1*delta_x1+coeff2*delta_y1*delta_y1
				+coeff3*delta_x1+coeff4*delta_y1
				+coeff5*delta_x1*delta_y1);
				
		 max2 = (coeff1*delta_x2*delta_x2+coeff2*delta_y2*delta_y2
				+coeff3*delta_x2+coeff4*delta_y2
				+coeff5*delta_x2*delta_y2
				+coeff6)/18.0;
		if(max1>max2) {
			*delta_x=delta_x1;
			*delta_y=delta_x1;
//			printf("x: %f - y: %f\n",delta_x, delta_y);
			return max1;
			printf("%fvvvv", max1);
		}
		else{
			*delta_x=delta_x2;
			*delta_y=delta_x2;
			return max2;
			printf("%fvvvv", max2);
		}
		
	}
	// this is the case of the maximum inside the boundaries:
//	printf("x: %f - y: %f\n",delta_x, delta_y);
	return (coeff1*(*delta_x)*(*delta_x)+coeff2*(*delta_y)*(*delta_y)
			+coeff3*(*delta_x)+coeff4*(*delta_y)
			+coeff5*(*delta_x)*(*delta_y)
			+coeff6)/18.0;
//	printf("hello");
}
float getScoreMaxBelow(const int layer,
		const int x_layer, const int y_layer,
		const int threshold, bool* ismax,
		float* dx, float* dy){
	*ismax=false;
	int x, y;
	// relevant floating point coordinates
	float x_1;
	float x1;
	float y_1;
	float y1;
	
	if(layer%2==0){
		// octave
		x_1=(float)(8*(x_layer)+1-4)/6.0;
		x1=(float)(8*(x_layer)+1+4)/6.0;
		y_1=(float)(8*(y_layer)+1-4)/6.0;
		y1=(float)(8*(y_layer)+1+4)/6.0;
	}
	else{
		x_1=(float)(6*(x_layer)+1-3)/4.0;
		x1=(float)(6*(x_layer)+1+3)/4.0;
		y_1=(float)(6*(y_layer)+1-3)/4.0;
		y1=(float)(6*(y_layer)+1+3)/4.0;
	}
	// the layer below
	assert(layer>0);
//	BriskLayer& layerBelow=pyramid_[layer-1];
	// check the first row
	int max_x = x_1+1;
	int max_y = y_1+1;
	float tmp_max;
	float max=scoref(layer-1, x_1, y_1, threshold);
	if(max>threshold) return 0;
	for(x=x_1+1; x<=(int)(x1); x++){
		tmp_max=scoref(layer-1, (float)(x), y_1, 1);
		if(tmp_max>threshold) return 0;
		if(tmp_max>max){
			max=tmp_max;
			max_x = x;
		}
	}
	tmp_max=scoref(layer-1, x1, y_1, 1);
	if(tmp_max>threshold) return 0;
	if(tmp_max>max){
		max=tmp_max;
		max_x = (int)(x1);
	}
	// middle rows
	for(y=y_1+1; y<=(int)(y1); y++){
		tmp_max=scoref(layer-1, x_1, (float)(y), 1);
		if(tmp_max>threshold) return 0;
		if(tmp_max>max){
			max=tmp_max;
			max_x = (int)(x_1+1);
			max_y = y;
		}
		for(x=x_1+1; x<=(int)(x1); x++){
			tmp_max=score(layer-1, x, y, 1);
			if(tmp_max>threshold) return 0;
			if(tmp_max==max){
				const int t1=2*(
						score(layer-1, x-1, y, 1)
						+score(layer-1, x+1, y, 1)
						+score(layer-1, x, y+1, 1)
						+score(layer-1, x, y-1, 1))
						+(score(layer-1, x+1, y+1, 1)
						+score(layer-1, x-1, y+1, 1)
						+score(layer-1, x+1, y-1, 1)
						+score(layer-1, x-1, y-1, 1));
				const int t2=2*(
						score(layer-1, max_x-1, max_y, 1)
						+score(layer-1, max_x+1, max_y, 1)
						+score(layer-1, max_x, max_y+1, 1)
						+score(layer-1, max_x, max_y-1, 1))
						+(score(layer-1, max_x+1, max_y+1, 1)
						+score(layer-1, max_x-1, max_y+1, 1)
						+score(layer-1, max_x+1, max_y-1, 1)
						+score(layer-1, max_x-1, max_y-1, 1));
				if(t1>t2){
					max_x = x;
					max_y = y;
				}
			}
			if(tmp_max>max){
				max=tmp_max;
				max_x = x;
				max_y = y;
			}
		}
		tmp_max=scoref(layer-1, x1, (float)(y), 1);
		if(tmp_max>threshold) return 0;
		if(tmp_max>max){
			max=tmp_max;
			max_x = (int)(x1);
			max_y = y;
		}
	}
	// bottom row
	tmp_max=scoref(layer-1, x_1, y1, 1);
	if(tmp_max>max){
		max=tmp_max;
		max_x = (int)(x_1+1);
		max_y = (int)(y1);
	}
	for(x=x_1+1; x<=(int)(x1); x++){
		tmp_max=scoref(layer-1, (float)(x), y1, 1);
		if(tmp_max>max){
			max=tmp_max;
			max_x = x;
			max_y = (int)(y1);
		}
	}
	tmp_max=scoref(layer-1, x1, y1, 1);
	if(tmp_max>max){
		max=tmp_max;
		max_x = (int)(x1);
		max_y = (int)(y1);
	}
	//find dx/dy:
	register int s_0_0 = score(layer-1, max_x-1, max_y-1, 1);
	register int s_1_0 = score(layer-1, max_x, max_y-1, 1);
	register int s_2_0 = score(layer-1, max_x+1, max_y-1, 1);
	register int s_2_1 = score(layer-1, max_x+1, max_y, 1);
	register int s_1_1 = score(layer-1, max_x, max_y, 1);
	register int s_0_1 = score(layer-1, max_x-1, max_y, 1);
	register int s_0_2 = score(layer-1, max_x-1, max_y+1, 1);
	register int s_1_2 = score(layer-1, max_x, max_y+1, 1);
	register int s_2_2 = score(layer-1, max_x+1, max_y+1, 1);
	float dx_1, dy_1;
	float refined_max=subpixel2D(s_0_0, s_0_1,  s_0_2,
			s_1_0, s_1_1, s_1_2,
			s_2_0, s_2_1, s_2_2,
			&dx_1, &dy_1);
	// calculate dx/dy in above coordinates
	float real_x = (float)(max_x)+dx_1;
	float real_y = (float)(max_y)+dy_1;
	bool returnrefined=true;
	if(layer%2==0){
		*dx=(real_x*6.0+1.0)/8.0-(float)(x_layer);
		*dy=(real_y*6.0+1.0)/8.0-(float)(y_layer);
	}
	else{
		*dx=(real_x*4.0-1.0)/6.0-(float)(x_layer);
		*dy=(real_y*4.0-1.0)/6.0-(float)(y_layer);
	}
	// saturate
	if(*dx>1.0) {*dx=1.0;returnrefined=false;}
	if(*dx<-1.0) {*dx=-1.0;returnrefined=false;}
	if(*dy>1.0) {*dy=1.0;returnrefined=false;}
	if(*dy<-1.0) {*dy=-1.0;returnrefined=false;}
	// done and ok.
	*ismax=true;
	if(returnrefined){
		if (refined_max > max)
		return refined_max;
		else
		return max;
	}
	return max;
}
float getScoreMaxAbove(const int layer,
		const int x_layer, const int y_layer,
		const int threshold, bool* ismax,
		float* dx, float* dy){
	
	*ismax=false;
	int x, y;
	// relevant floating point coordinates
	float x_1;
	float x1;
	float y_1;
	float y1;
	// the layer above
	assert(layer+1<layers);
//	BriskLayer& layerAbove=pyramid_[layer+1];
	if(layer%2==0) {
		// octave
		x_1=(float)(4*(x_layer)-1-2)/6.0;
		x1=(float)(4*(x_layer)-1+2)/6.0;
		y_1=(float)(4*(y_layer)-1-2)/6.0;
		y1=(float)(4*(y_layer)-1+2)/6.0;
	}
	else{
		// intra
		x_1=(float)(6*(x_layer)-1-3)/8.0f;
		x1=(float)(6*(x_layer)-1+3)/8.0f;
		y_1=(float)(6*(y_layer)-1-3)/8.0f;
		y1=(float)(6*(y_layer)-1+3)/8.0f;
	}
	// check the first row
	int max_x = x_1+1;
	int max_y = y_1+1;
	float tmp_max;
	float max=scoref(layer+1, x_1, y_1, 1);
	if(max>threshold) return 0;
	for(x=x_1+1; x<=(int)(x1); x++){
		tmp_max=scoref(layer+1, (float)(x), y_1, 1);
		if(tmp_max>threshold) return 0;
		if(tmp_max>max){
			max=tmp_max;
			max_x = x;
		}
	}
	tmp_max=scoref(layer+1, x1, y_1, 1);
	if(tmp_max>threshold) return 0;
	if(tmp_max>max){
		max=tmp_max;
		max_x = (int)(x1);
	}
	// middle rows
	for(y=y_1+1; y<=(int)(y1); y++){
		tmp_max=scoref(layer+1, x_1, (float)(y), 1);
		if(tmp_max>threshold) return 0;
		if(tmp_max>max){
			max=tmp_max;
			max_x = (int)(x_1+1);
			max_y = y;
		}
		for(x=x_1+1; x<=(int)(x1); x++){
			tmp_max=score(layer+1, x, y, 1);
			if(tmp_max>threshold) return 0;
			if(tmp_max>max){
				max=tmp_max;
				max_x = x;
				max_y = y;
			}
		}
		tmp_max=scoref(layer+1, x1, (float)(y), 1);
		if(tmp_max>threshold) return 0;
		if(tmp_max>max){
			max=tmp_max;
			max_x = (int)(x1);
			max_y = y;
		}
	}
	// bottom row
	tmp_max=scoref(layer+1, x_1, y1, 1);
	if(tmp_max>max){
		max=tmp_max;
		max_x = (int)(x_1+1);
		max_y = (int)(y1);
	}
	for(x=x_1+1; x<=(int)(x1); x++){
		tmp_max=scoref(layer+1, (float)(x), y1, 1);
		if(tmp_max>max){
			max=tmp_max;
			max_x = x;
			max_y = (int)(y1);
		}
	}
	tmp_max=scoref(layer+1, x1, y1, 1);
	if(tmp_max>max){
		max=tmp_max;
		max_x = (int)(x1);
		max_y = (int)(y1);
	}
	//find dx/dy:
	register int s_0_0 = score(layer+1, max_x-1, max_y-1, 1);
	register int s_1_0 = score(layer+1, max_x, max_y-1, 1);
	register int s_2_0 = score(layer+1, max_x+1, max_y-1, 1);
	register int s_2_1 = score(layer+1, max_x+1, max_y, 1);
	register int s_1_1 = score(layer+1, max_x, max_y, 1);
	register int s_0_1 = score(layer+1, max_x-1, max_y, 1);
	register int s_0_2 = score(layer+1, max_x-1, max_y+1, 1);
	register int s_1_2 = score(layer+1, max_x, max_y+1, 1);
	register int s_2_2 = score(layer+1, max_x+1, max_y+1, 1);
	float dx_1, dy_1;
	float refined_max=subpixel2D(s_0_0, s_0_1,  s_0_2,
			s_1_0, s_1_1, s_1_2,
			s_2_0, s_2_1, s_2_2,
			&dx_1, &dy_1);
	// calculate dx/dy in above coordinates
	float real_x = (float)(max_x)+dx_1;
	float real_y = (float)(max_y)+dy_1;
	bool returnrefined=true;
	if(layer%2==0){
		*dx=(real_x*6.0f+1.0f)/4.0f-(float)(x_layer);
		*dy=(real_y*6.0f+1.0f)/4.0f-(float)(y_layer);
	}
	else{
		*dx=(real_x*8.0+1.0)/6.0-(float)(x_layer);
		*dy=(real_y*8.0+1.0)/6.0-(float)(y_layer);
	}
	// saturate
	if(*dx>1.0f) {*dx=1.0f;returnrefined=false;}
	if(*dx<-1.0f) {*dx=-1.0f;returnrefined=false;}
	if(*dy>1.0f) {*dy=1.0f;returnrefined=false;}
	if(*dy<-1.0f) {*dy=-1.0f;returnrefined=false;}
	// done and ok.
	*ismax=true;
	if(returnrefined){
		if ((float)refined_max > (float)max)
		return refined_max;
		else
		return max;
	}
//	return max;
}
float refine1D(const float s_05,
				const float s0, const float s05, float* max){
	int i_05=(int)(1024.0*s_05+0.5);
	int i0=(int)(1024.0*s0+0.5);
	int i05=(int)(1024.0*s05+0.5);
	//   16.0000  -24.0000    8.0000
	//  -40.0000   54.0000  -14.0000
	//   24.0000  -27.0000    6.0000
	int three_a=16*i_05-24*i0+8*i05;
	// second derivative must be negative:
	if(three_a>=0){
		if(s0>=s_05 && s0>=s05){
			*max=s0;
			return 1.0;
		}
		if(s_05>=s0 && s_05>=s05){
			*max=s_05;
			return 0.75;
		}
		if(s05>=s0 && s05>=s_05){
			*max=s05;
			return 1.5;
		}
	}
	int three_b=-40*i_05+54*i0-14*i05;
	// calculate max location:
	float ret_val=-(float)(three_b)/(float)(2*three_a);
	// saturate and return
	if(ret_val<0.75) ret_val= 0.75;
	else if(ret_val>1.5) ret_val= 1.5; // allow to be slightly off bounds ...?
	int three_c = +24*i_05  -27*i0    +6*i05;
	*max=(float)(three_c)+(float)(three_a)*ret_val*ret_val+(float)(three_b)*ret_val;
	*max/=3072.0;
	return ret_val;
}
float refine1D_1(const float s_05,
				const float s0, const float s05, float* max){
	int i_05=(int)(1024.0*s_05+0.5);
	int i0=(int)(1024.0*s0+0.5);
	int i05=(int)(1024.0*s05+0.5);
    //  4.5000   -9.0000    4.5000
    //-10.5000   18.0000   -7.5000
    //  6.0000   -8.0000    3.0000
	int two_a=9*i_05-18*i0+9*i05;
	// second derivative must be negative:
	if(two_a>=0){
		if(s0>=s_05 && s0>=s05){
			*max=s0;
			return 1.0;
		}
		if(s_05>=s0 && s_05>=s05){
			*max=s_05;
			return 0.6666666666666666666666666667;
		}
		if(s05>=s0 && s05>=s_05){
			*max=s05;
			return 1.3333333333333333333333333333;
		}
	}
	int two_b=-21*i_05+36*i0-15*i05;
	// calculate max location:
	float ret_val=-(float)(two_b)/(float)(2*two_a);
	// saturate and return
	if(ret_val<0.6666666666666666666666666667) ret_val= 0.666666666666666666666666667;
	else if(ret_val>1.33333333333333333333333333) ret_val= 1.333333333333333333333333333;
	int two_c = +12*i_05  -16*i0    +6*i05;
	*max=(float)(two_c)+(float)(two_a)*ret_val*ret_val+(float)(two_b)*ret_val;
	*max/=2048.0;
	return ret_val;
}
float refine1D_2(const float s_05,
				const float s0, const float s05, float* max){
	int i_05=(int)(1024.0*s_05+0.5);
	int i0=(int)(1024.0*s0+0.5);
	int i05=(int)(1024.0*s05+0.5);
	//   18.0000  -30.0000   12.0000
	//  -45.0000   65.0000  -20.0000
	//   27.0000  -30.0000    8.0000
	int a=2*i_05-4*i0+2*i05;
	// second derivative must be negative:
	if(a>=0){
		if(s0>=s_05 && s0>=s05){
			*max=s0;
			return 1.0;
		}
		if(s_05>=s0 && s_05>=s05){
			*max=s_05;
			return 0.7;
		}
		if(s05>=s0 && s05>=s_05){
			*max=s05;
			return 1.5;
		}
	}
	int b=-5*i_05+8*i0-3*i05;
	// calculate max location:
	float ret_val=-(float)(b)/(float)(2*a);
	// saturate and return
	if(ret_val<0.7) ret_val= 0.7;
	else if(ret_val>1.5) ret_val= 1.5; // allow to be slightly off bounds ...?
	int c = +3*i_05  -3*i0    +1*i05;
	*max=(float)(c)+(float)(a)*ret_val*ret_val+(float)(b)*ret_val;
	*max/=1024;
	return ret_val;
}
float refine3D(const int layer,
		const int x_layer, const int y_layer,
		float* x, float* y, float* scale, bool* ismax){
	
//	bool *ismaxb;
	*ismax=true;
	const int center = score(layer, x_layer, y_layer, 1);
//	printf("%d\n\n", center);
	// check and get above maximum:
	float delta_x_above, delta_y_above;
	float max_above = getScoreMaxAbove(layer,x_layer, y_layer,
					center, ismax,
					&delta_x_above, &delta_y_above);
	if(!*ismax) return 0.0;
	float max; // to be returned
//if (count == 0)
	if(layer==0 || layer ==2 || layer == 4 || layer ==6){ // on octave
		// treat the patch below:
		float delta_x_below, delta_y_below;
		float max_below_float;
		uchar max_below_uchar=0;
		if(layer==0){
			// guess the lower intra octave...
			register int s_0_0 = getAgastScore_5_8(x_layer-1, y_layer-1, 1);
			max_below_uchar=s_0_0;
			register int s_1_0 = getAgastScore_5_8(x_layer,   y_layer-1, 1);
			if(s_1_0>max_below_uchar) max_below_uchar=s_1_0;
			register int s_2_0 = getAgastScore_5_8(x_layer+1, y_layer-1, 1);
			if(s_2_0>max_below_uchar) max_below_uchar=s_2_0;
			register int s_2_1 = getAgastScore_5_8(x_layer+1, y_layer,   1);
			if(s_2_1>max_below_uchar) max_below_uchar=s_2_1;
			register int s_1_1 = getAgastScore_5_8(x_layer,   y_layer,   1);
			if(s_1_1>max_below_uchar) max_below_uchar=s_1_1;
			register int s_0_1 = getAgastScore_5_8(x_layer-1, y_layer,   1);
			if(s_0_1>max_below_uchar) max_below_uchar=s_0_1;
			register int s_0_2 = getAgastScore_5_8(x_layer-1, y_layer+1, 1);
			if(s_0_2>max_below_uchar) max_below_uchar=s_0_2;
			register int s_1_2 = getAgastScore_5_8(x_layer,   y_layer+1, 1);
			if(s_1_2>max_below_uchar) max_below_uchar=s_1_2;
			register int s_2_2 = getAgastScore_5_8(x_layer+1, y_layer+1, 1);
			if(s_2_2>max_below_uchar) max_below_uchar=s_2_2;
			
//			printf("%d\n", max_below_uchar);
//			printf("%d %d %d %d %d %d %d %d\n", s_1_0, s_2_0, s_2_1, s_1_1, s_0_1, s_0_2, s_1_2, s_2_2);
			
			max_below_float = subpixel2D(s_0_0, s_0_1, s_0_2,
							s_1_0, s_1_1, s_1_2,
							s_2_0, s_2_1, s_2_2,
							&delta_x_below, &delta_y_below);
			max_below_float = max_below_uchar;
		}
		else{
			max_below_float = getScoreMaxBelow(layer,x_layer, y_layer,
								center, ismax,
								&delta_x_below, &delta_y_below);
			if(!*ismax) return 0;
		}
		// get the patch on this layer:
		register int s_0_0 = getAgastScore(layer, x_layer-1, y_layer-1,1);
		register int s_1_0 = getAgastScore(layer, x_layer,   y_layer-1,1);
		register int s_2_0 = getAgastScore(layer, x_layer+1, y_layer-1,1);
		register int s_2_1 = getAgastScore(layer, x_layer+1, y_layer,1);
		register int s_1_1 = getAgastScore(layer, x_layer,   y_layer,1);
		register int s_0_1 = getAgastScore(layer, x_layer-1, y_layer,1);
		register int s_0_2 = getAgastScore(layer, x_layer-1, y_layer+1,1);
		register int s_1_2 = getAgastScore(layer, x_layer,   y_layer+1,1);
		register int s_2_2 = getAgastScore(layer, x_layer+1, y_layer+1,1);
		float delta_x_layer, delta_y_layer;
		float max_layer = subpixel2D(s_0_0, s_0_1, s_0_2,
				s_1_0, s_1_1, s_1_2,
				s_2_0, s_2_1, s_2_2,
				&delta_x_layer, &delta_y_layer);
		// calculate the relative scale (1D maximum):
		
			float m;
			if ((float)(center) > max_layer)
			m = (float)(center);
			else m = max_layer;
//			printf("%f\n", m);
		if(layer==0){
			*scale=refine1D_2(max_below_float,
					m, max_above,&max);
		}
		else
			*scale=refine1D(max_below_float,
					m, max_above,&max);
//		printf("%f\n", scale);
		if(*scale>1.0){
			// interpolate the position:
			const float r0=(1.5-*scale)/.5;
			const float r1=1.0-r0;
			*x=(r0*delta_x_layer+r1*delta_x_above+(float)(x_layer))
					*oscale[layer]+offset[layer];
			*y=(r0*delta_y_layer+r1*delta_y_above+(float)(y_layer))
				*oscale[layer]+offset[layer];
		}
		else{
			if(layer==0){
				// interpolate the position:
				const float r0=(*scale-0.5)/0.5;
				const float r_1=1.0-r0;
				*x=r0*delta_x_layer+r_1*delta_x_below+(float)(x_layer);
				*y=r0*delta_y_layer+r_1*delta_y_below+(float)(y_layer);
			}
			else{
				// interpolate the position:
				const float r0=(*scale-0.75)/0.25;
				const float r_1=1.0-r0;
				*x=(r0*delta_x_layer+r_1*delta_x_below+(float)(x_layer))
						*oscale[layer]+offset[layer];
				*y=(r0*delta_y_layer+r_1*delta_y_below+(float)(y_layer))
						*oscale[layer]+offset[layer];
			}
		}
	}
	else{
		// on intra
		// check the patch below:
		float delta_x_below, delta_y_below;
		float max_below = getScoreMaxBelow(layer,x_layer, y_layer,
					center, ismax,
					&delta_x_below, &delta_y_below);
		if(!*ismax) return 0.0;
		// get the patch on this layer:
		register int s_0_0 = getAgastScore(layer, x_layer-1, y_layer-1,1);
		register int s_1_0 = getAgastScore(layer, x_layer,   y_layer-1,1);
		register int s_2_0 = getAgastScore(layer, x_layer+1, y_layer-1,1);
		register int s_2_1 = getAgastScore(layer, x_layer+1, y_layer,1);
		register int s_1_1 = getAgastScore(layer, x_layer,   y_layer,1);
		register int s_0_1 = getAgastScore(layer, x_layer-1, y_layer,1);
		register int s_0_2 = getAgastScore(layer, x_layer-1, y_layer+1,1);
		register int s_1_2 = getAgastScore(layer, x_layer,   y_layer+1,1);
		register int s_2_2 = getAgastScore(layer, x_layer+1, y_layer+1,1);
		float delta_x_layer, delta_y_layer;
		float max_layer = subpixel2D(s_0_0, s_0_1, s_0_2,
				s_1_0, s_1_1, s_1_2,
				s_2_0, s_2_1, s_2_2,
				&delta_x_layer, &delta_y_layer);
		// calculate the relative scale (1D maximum):
			float m;
			if ((float)(center) > max_layer)
			m = (float)(center);
			else m = max_layer;
		
		*scale=refine1D_1(max_below,
				m, max_above,&max);
		if(*scale>1.0){
			// interpolate the position:
			const float r0=4.0-*scale*3.0;
			const float r1=1.0-r0;
			*x=(r0*delta_x_layer+r1*delta_x_above+(float)(x_layer))
					*oscale[layer]+offset[layer];
			*y=(r0*delta_y_layer+r1*delta_y_above+(float)(y_layer))
					*oscale[layer]+offset[layer];
		}
		else{
			// interpolate the position:
			const float r0=*scale*3.0-2.0;
			const float r_1=1.0-r0;
			*x=(r0*delta_x_layer+r_1*delta_x_below+(float)(x_layer))
				*oscale[layer]+offset[layer];
			*y=(r0*delta_y_layer+r_1*delta_y_below+(float)(y_layer))
				*oscale[layer]+offset[layer];
		}
	}
	// calculate the absolute scale:
	*scale*=oscale[layer];
	
	// that's it, return the refined maximum:
//	count++;
	return max;
}
void getKeypoints()
{	
	// FILE
	
	FILE *file_corners = fopen("C:\\Users\\kkumar\\Documents\\Oulu\\Kushal\\Keypoints\\file.txt", "w");
	if (file_corners == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}
	
	/* print some text */
//	const char *text = "Write this to the file";
//	fprintf(f, "Some text: %s\n", text);
	
	/* print integers and floats */
//	int i = 1;
//	float py = 3.1415927;
//	fprintf(f, "Integer: %d, float: %f\n", i, py);
	
	/* printing single chatacters */
//	char c = 'A';
//	fprintf(f, "A character: %c\n", c);
	
	
	//END OF FILE
	int i, j, f = 0, threshold = 1.0, s_0_0, s_1_0, s_2_0, s_2_1, s_1_1, s_0_1, s_0_2, s_1_2, s_2_2, num_corners, n, k, l, m, g = 0;
	
	float **bettercorners;
	
	my_offsetof();
	
 	
 	
 	int layers = 8;
 	
	scoremat = (int ***)malloc(9*sizeof(int**));
    for (i = 0; i< layers+1; i++) 
	{
		scoremat[i] = (int **) calloc(pyramid[0].width, sizeof(int *));
		for (j = 0; j < pyramid[0].width; j++) 
		{
        	scoremat[i][j] = (int *) calloc(pyramid[0].height, sizeof(int));
        }
    }  
	scoremat5 = malloc( pyramid[0].height * sizeof(int*) );
	for(f = 0; f<pyramid[0].height; f++)
	{
		scoremat5[f] = (int*) calloc( pyramid[0].width , sizeof(int*) );
	}
	bettercorners = malloc( 5000 * sizeof(float*) );
	for(f = 0; f<5000; f++)
	{
		bettercorners[f] = (float*) calloc( 2 , sizeof(float*) );
	}
	imgcharmatrix();
//		printf("%d", img_char[1]);
//		printf("Wadda Hello!");
//		transformImageToByte(&pyramid[0], img_char[0]);
//	printf("Hello!");
		int positionx = 0;
		float scale, x, y, score;
//		for (i = 0; i < 8 ; i++){
//				
//				corners = fast9_detect(img_char[i], pyramid[i].width, pyramid[i].height, pyramid[i].width, 60, &num_corners);
////				printf("%d\n", num_corners);
//
//				fast9_score(img_char[i], pyramid[i].width, corners, num_corners, 1, pyramid[i].height, scores, i, scoremat);
//				
//				
//			}
		for (i = 0; i<1; i++)
		{	 
			
			float s;
			
			if(i==7)
			{
				corners = fast9_detect(img_char[i], pyramid[i].width, pyramid[i].height, pyramid[i].width, 60, &num_corners);
					fast9_score(img_char[i], pyramid[i].width, corners, num_corners, 1, pyramid[i].height, scores, i, scoremat);
//					printf("%d\n", num_corners);
				for(n=0; n < num_corners; n++)
				{
					
					// first check if it is a maximum:
					
					if (!isMax2D(i, corners[n].x, corners[n].y, scores))
						continue;
//					printf("%d %d\n", corners[n].x, corners[n].y);
					bool ismax;
					float dx, dy;
					getScoreMaxBelow(i, corners[n].x, corners[n].y,
						scores[corners[n].x][corners[n].y], &ismax,
						&dx, &dy);
						
					if(!ismax)
						continue;
					
				// get the patch on this layer:
				register int s_0_0 = getAgastScore(i, corners[n].x-1, corners[n].y-1, 1);
				register int s_1_0 = getAgastScore(i, corners[n].x, corners[n].y-1, 1);
				register int s_2_0 = getAgastScore(i, corners[n].x+1, corners[n].y-1, 1);
				register int s_2_1 = getAgastScore(i, corners[n].x+1, corners[n].y, 1);
				register int s_1_1 = getAgastScore(i, corners[n].x, corners[n].y, 1);
				register int s_0_1 = getAgastScore(i, corners[n].x-1, corners[n].y, 1);
				register int s_0_2 = getAgastScore(i, corners[n].x-1, corners[n].y+1, 1);
				register int s_1_2 = getAgastScore(i, corners[n].x, corners[n].y+1, 1);
				register int s_2_2 = getAgastScore(i, corners[n].x+1, corners[n].y+1, 1);
				float delta_x;
				float delta_y;
				float max = subpixel2D(s_0_0, s_0_1, s_0_2,
						s_1_0, s_1_1, s_1_2,
						s_2_0, s_2_1, s_2_2,
						&delta_x, &delta_y);
//			printf("%f\n", oscale[i]);
//			if (x < pyramid[0].height && y < pyramid[0].width){	
			bettercorners[positionx][0] = ((float)corners[n].x+delta_x)*oscale[i] + offset[i];
			bettercorners[positionx][1] = ((float)corners[n].y+delta_y)*oscale[i] + offset[i];
			positionx++;
//			}
//			printf("%f %f\n", ((float)corners[n].x+delta_x)*oscale[i] + offset[i], ((float)corners[n].y+delta_y)*oscale[i] + offset[i]);
			}
			printf("Number of corners: %d\n", positionx);
		}
		
else{
		scores = malloc( pyramid[i].height * sizeof(int*) );
		for(f = 0; f<pyramid[i].height; f++)
		{
			scores[f] = (int*) calloc( pyramid[i].width , sizeof(int*) );
		}
//			 not the last layer:
				corners = fast9_detect(img_char[i], pyramid[i].width, pyramid[i].height, pyramid[i].width, 60, &num_corners);
				fast9_score(img_char[i], pyramid[i].width, corners, num_corners, 60, pyramid[i].height, scores, i, scoremat);
				
//				printf("%u", img_char[2000]);
//				printf("%d\n", num_corners);
//				if (scoremat[i][x][y] == )
//				printf("%d %d %d\n", corners[n].x, corners[n].y, scores[corners[n].x][corners[n].y]);
				int counterb = 0;
				for(n=0; n < num_corners; n++){
			// first check if it is a maximum:
//			printf("bla: %d %d\n", corners[n].x, corners[n].y);
			if (!isMax2D(i, corners[n].x, corners[n].y, scores))
				continue;
				
//				printf("Corner %d: %d %d %d\n", n,corners[n].x, corners[n].y, scores[corners[n].x][corners[n].y]);
				
				counterb = counterb + 1;
//				printf("%d %d %d %d\n", counterb, corners[n].x, corners[n].y, scores[corners[n].x][corners[n].y]); 
		
//			printf("%d %d\n", corners[n].x, corners[n].y);
		
			// let's do the subpixel and float scale refinement:
				bool ismax;
					
//				if (ismax){
//			
//				
//			}
				score = refine3D(i,corners[n].x, corners[n].y,&x,&y,&s,&ismax);
//				printf("%f\n", score);
				
//			printf("%f\n", score);
//			scale[i] = s;
			if(!ismax){
				continue;
			}
			
//			printf("%d\n", n);
//			if(score>(float)(20)){
			
			// finally store the detected keypoint:
//			if (x < pyramid[0].height && y < pyramid[0].width)
//			{
			bettercorners[positionx][0] = x;
			bettercorners[positionx][1] = y;
			
			positionx++;
//			fprintf(file_corners, "%f,%f,%f,-1\n", x, y, s);
//			}
//		}
			printf("%f %f %f\n", x, y, s);
			}
//			printf("Number of corners: %d\n", positionx);
//			printf("%d\n", counterb);
		}
			printf("Number of corners: %d\n", positionx);
	}
	fclose(file_corners);
}
bool isMax2D(const layer, const int x_layer, const int y_layer, int **scores)
{
//	int scores[pyramid[layer].height][pyramid[layer].width];
	
	const int scorescols = pyramid[layer].width;
	
	uchar data=scores[x_layer][y_layer];
//	printf("hello\n");
	// decision tree:
	const uchar center = (data);
//	printf(" %d %d %d\n", (int)center, x_layer, y_layer);
//	data--;
	data=scores[x_layer-1][y_layer];
	const uchar s_10=data;
	if(center<s_10) return false;
//	data+=2;
	data=scores[x_layer+1][y_layer];
	const uchar s10=data;
	if(center<s10) return false;
//	data-=(scorescols+1);
	data=scores[x_layer][y_layer-1];
	const uchar s0_1=data;
	if(center<s0_1) return false;
//	data+=2*scorescols;
	data=scores[x_layer][y_layer+1];
	const uchar s01=data;
	if(center<s01) return false;
//	data--;
	data=scores[x_layer-1][y_layer+1];
	const uchar s_11=data;
	if(center<s_11) return false;
//	data+=2;
	data=scores[x_layer+1][y_layer+1];
	const uchar s11=data;
	if(center<s11) return false;
//	data-=2*scorescols;
	data=scores[x_layer+1][y_layer-1];
	const uchar s1_1=data;
	if(center<s1_1) return false;
//	data-=2;
	data=scores[x_layer-1][y_layer-1];
	const uchar s_1_1=data;
	if(center<s_1_1) return false;
	// reject neighbor maxima
	int counter = 0;
	int delta[16];
	// put together a list of 2d-offsets to where the maximum is also reached
	if(center==s_1_1) {
		delta[counter*2] = -1;
		delta[counter*2+1] = -1;
		counter++;
	}
	if(center==s0_1) {
		delta[counter*2] = 0;
		delta[counter*2+1] = -1;
		counter++;
	}
	if(center==s1_1) {
		delta[counter*2] = 1;
		delta[counter*2+1] = -1;
		counter++;
	}
	if(center==s_10) {
		delta[counter*2] = -1;
		delta[counter*2+1] = 0;
		counter++;
	}
	if(center==s10) {
		delta[counter*2] = 1;
		delta[counter*2+1] = 0;
		counter++;
	}
	if(center==s_11) {
		delta[counter*2] = -1;
		delta[counter*2+1] = 1;
		counter++;
	}
	if(center==s01) {
		delta[counter*2] = 0;
		delta[counter*2+1] = 1;
		counter++;
	}
	if(center==s11) {
		delta[counter*2] = 1;
		delta[counter*2+1] = 1;
		counter++;
	}
//	const unsigned int deltasize=sizeof(delta);
	if(counter!=0){
		unsigned int i;
		// in this case, we have to analyze the situation more carefully:
		// the values are gaussian blurred and then we really decide
		data=scores[x_layer][y_layer];
		int smoothedcenter=4*center+2*(s_10+s10+s0_1+s01)+s_1_1+s1_1+s_11+s11;
		for(i=0; i<counter;i++){
			int new_x_layer = x_layer+delta[i*2]-1;
			int new_y_layer = y_layer-1+delta[i*2+1];
			data = scores[new_x_layer][new_y_layer];
			int othercenter=data;
//			data++;
			data = scores[new_x_layer+1][new_y_layer];
			othercenter+=2*(data);
//			data++;
			data = scores[new_x_layer+2][new_y_layer];
			othercenter+=data;
//			data+=scorescols;
			data = scores[new_x_layer+2][new_y_layer+1];
			othercenter+=2*(data);
//			data--;
			data = scores[new_x_layer+1][new_y_layer+1];
			othercenter+=4*(data);
//			data--;
			data = scores[new_x_layer][new_y_layer+1];
			othercenter+=2*(data);
//			data+=scorescols;
			data = scores[new_x_layer][new_y_layer+2];
			othercenter+=data;
//			data++;
			data = scores[new_x_layer+1][new_y_layer+2];
			othercenter+=2*(data);
//			data++;
			data = scores[new_x_layer+2][new_y_layer+2];
			othercenter+=data;
			if(othercenter>smoothedcenter)
			{
				return false;
			} 
		}
	}
	return true;
}
