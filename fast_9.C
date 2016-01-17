#include <stdlib.h>
#include<stdio.h>
#include <math.h>
#include "fast.h"
typedef unsigned char byte;
typedef unsigned char uchar;
struct image {
    int **image;
    int    height;
    int    width;
};
static xy* h;
static int nExpectedCorners=0;
int whatever = 0;
int fast9_corner_score(const byte* p, const int pixel[], int bstart, int stride)
{    
    int bmin = bstart;
    int bmax = 255;
    int b_test = (bmax + bmin)/2;
    int offset0, offset1, offset2, offset3, offset4, offset5, offset6, offset7, offset8, offset9, offset10, offset11, offset12, offset13, offset14, offset15;
    		int		s_offset0=(-3)+(0)*stride;
			int 	s_offset1=(-3)+(-1)*stride;
			int 	s_offset2=(-2)+(-2)*stride;
			int 	s_offset3=(-1)+(-3)*stride;
			int 	s_offset4=(0)+(-3)*stride;
			int 	s_offset5=(1)+(-3)*stride;
			int 	s_offset6=(2)+(-2)*stride;
			int 	s_offset7=(3)+(-1)*stride;
			int 	s_offset8=(3)+(0)*stride;
			int 	s_offset9=(3)+(1)*stride;
			int 	s_offset10=(2)+(2)*stride;
			int 	s_offset11=(1)+(3)*stride;
			int 	s_offset12=(0)+(3)*stride;
			int 	s_offset13=(-1)+(3)*stride;
			int 	s_offset14=(-2)+(2)*stride;
			int 	s_offset15=(-3)+(1)*stride;
//	offset0=*p + s_offset0;
//    offset1=*p + s_offset1;
//    offset2=*p + s_offset2;
//    offset3=*p + s_offset3;
//    offset4=*p + s_offset4;
//    offset5=*p + s_offset5;
//    offset6=*p + s_offset6;
//    offset7=*p + s_offset7;
//    offset8=*p + s_offset8;
//    offset9=*p + s_offset9;
//    offset10=*p + s_offset10;
//    offset11=*p + s_offset11;
//    offset12=*p + s_offset12;
//    offset13=*p + s_offset13;
//    offset14=*p + s_offset14;
//    offset15=*p + s_offset15;
    
    offset0=s_offset0;
    offset1=s_offset1;
    offset2=s_offset2;
    offset3=s_offset3;
    offset4=s_offset4;
    offset5=s_offset5;
    offset6=s_offset6;
    offset7=s_offset7;
    offset8=s_offset8;
    offset9=s_offset9;
    offset10=s_offset10;
    offset11=s_offset11;
    offset12=s_offset12;
    offset13=s_offset13;
    offset14=s_offset14;
    offset15=s_offset15;
//    printf("%u\n", *p);
    /*Compute the score using binary search*/
    
	while(1)
	{
		register const int cb = *p + b_test;
		whatever++;
		if(whatever == 1)
			printf("%d %d\n",*p,p[offset0]);
		//std::csout << offset0 << ".";
		register const int c_b = *p - b_test;
		if(p[offset0] > cb)
		  if(p[offset2] > cb)
		    if(p[offset4] > cb)
		      if(p[offset5] > cb)
		        if(p[offset7] > cb)
		          if(p[offset3] > cb)
		            if(p[offset1] > cb)
		              if(p[offset6] > cb)
		                if(p[offset8] > cb)
		                  goto is_a_corner;
		                else
		                  if(p[offset15] > cb)
		                    goto is_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset13] > cb)
		                  if(p[offset14] > cb)
		                    if(p[offset15] > cb)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              if(p[offset8] > cb)
		                if(p[offset9] > cb)
		                  if(p[offset10] > cb)
		                    if(p[offset6] > cb)
		                      goto is_a_corner;
		                    else
		                      if(p[offset11] > cb)
		                        if(p[offset12] > cb)
		                          if(p[offset13] > cb)
		                            if(p[offset14] > cb)
		                              if(p[offset15] > cb)
		                                goto is_a_corner;
		                              else
		                                goto is_not_a_corner;
		                            else
		                              goto is_not_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            if(p[offset10] > cb)
		              if(p[offset11] > cb)
		                if(p[offset12] > cb)
		                  if(p[offset8] > cb)
		                    if(p[offset9] > cb)
		                      if(p[offset6] > cb)
		                        goto is_a_corner;
		                      else
		                        if(p[offset13] > cb)
		                          if(p[offset14] > cb)
		                            if(p[offset15] > cb)
		                              goto is_a_corner;
		                            else
		                              goto is_not_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                    else
		                      if(p[offset1] > cb)
		                        if(p[offset13] > cb)
		                          if(p[offset14] > cb)
		                            if(p[offset15] > cb)
		                              goto is_a_corner;
		                            else
		                              goto is_not_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                  else
		                    if(p[offset1] > cb)
		                      if(p[offset13] > cb)
		                        if(p[offset14] > cb)
		                          if(p[offset15] > cb)
		                            goto is_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		        else if(p[offset7] < c_b)
		          if(p[offset14] > cb)
		            if(p[offset15] > cb)
		              if(p[offset1] > cb)
		                if(p[offset3] > cb)
		                  if(p[offset6] > cb)
		                    goto is_a_corner;
		                  else
		                    if(p[offset13] > cb)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset10] > cb)
		                    if(p[offset11] > cb)
		                      if(p[offset12] > cb)
		                        if(p[offset13] > cb)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset8] > cb)
		                  if(p[offset9] > cb)
		                    if(p[offset10] > cb)
		                      if(p[offset11] > cb)
		                        if(p[offset12] > cb)
		                          if(p[offset13] > cb)
		                            goto is_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else if(p[offset14] < c_b)
		            if(p[offset8] < c_b)
		              if(p[offset9] < c_b)
		                if(p[offset10] < c_b)
		                  if(p[offset11] < c_b)
		                    if(p[offset12] < c_b)
		                      if(p[offset13] < c_b)
		                        if(p[offset6] < c_b)
		                          goto is_a_corner;
		                        else
		                          if(p[offset15] < c_b)
		                            goto is_a_corner;
		                          else
		                            goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          if(p[offset14] > cb)
		            if(p[offset15] > cb)
		              if(p[offset1] > cb)
		                if(p[offset3] > cb)
		                  if(p[offset6] > cb)
		                    goto is_a_corner;
		                  else
		                    if(p[offset13] > cb)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset10] > cb)
		                    if(p[offset11] > cb)
		                      if(p[offset12] > cb)
		                        if(p[offset13] > cb)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset8] > cb)
		                  if(p[offset9] > cb)
		                    if(p[offset10] > cb)
		                      if(p[offset11] > cb)
		                        if(p[offset12] > cb)
		                          if(p[offset13] > cb)
		                            goto is_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		      else if(p[offset5] < c_b)
		        if(p[offset12] > cb)
		          if(p[offset13] > cb)
		            if(p[offset14] > cb)
		              if(p[offset15] > cb)
		                if(p[offset1] > cb)
		                  if(p[offset3] > cb)
		                    goto is_a_corner;
		                  else
		                    if(p[offset10] > cb)
		                      if(p[offset11] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset8] > cb)
		                    if(p[offset9] > cb)
		                      if(p[offset10] > cb)
		                        if(p[offset11] > cb)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset6] > cb)
		                  if(p[offset7] > cb)
		                    if(p[offset8] > cb)
		                      if(p[offset9] > cb)
		                        if(p[offset10] > cb)
		                          if(p[offset11] > cb)
		                            goto is_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else if(p[offset12] < c_b)
		          if(p[offset7] < c_b)
		            if(p[offset8] < c_b)
		              if(p[offset9] < c_b)
		                if(p[offset10] < c_b)
		                  if(p[offset11] < c_b)
		                    if(p[offset13] < c_b)
		                      if(p[offset6] < c_b)
		                        goto is_a_corner;
		                      else
		                        if(p[offset14] < c_b)
		                          if(p[offset15] < c_b)
		                            goto is_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        if(p[offset12] > cb)
		          if(p[offset13] > cb)
		            if(p[offset14] > cb)
		              if(p[offset15] > cb)
		                if(p[offset1] > cb)
		                  if(p[offset3] > cb)
		                    goto is_a_corner;
		                  else
		                    if(p[offset10] > cb)
		                      if(p[offset11] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset8] > cb)
		                    if(p[offset9] > cb)
		                      if(p[offset10] > cb)
		                        if(p[offset11] > cb)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset6] > cb)
		                  if(p[offset7] > cb)
		                    if(p[offset8] > cb)
		                      if(p[offset9] > cb)
		                        if(p[offset10] > cb)
		                          if(p[offset11] > cb)
		                            goto is_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else if(p[offset12] < c_b)
		          if(p[offset7] < c_b)
		            if(p[offset8] < c_b)
		              if(p[offset9] < c_b)
		                if(p[offset10] < c_b)
		                  if(p[offset11] < c_b)
		                    if(p[offset13] < c_b)
		                      if(p[offset14] < c_b)
		                        if(p[offset6] < c_b)
		                          goto is_a_corner;
		                        else
		                          if(p[offset15] < c_b)
		                            goto is_a_corner;
		                          else
		                            goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		    else if(p[offset4] < c_b)
		      if(p[offset11] > cb)
		        if(p[offset12] > cb)
		          if(p[offset13] > cb)
		            if(p[offset10] > cb)
		              if(p[offset14] > cb)
		                if(p[offset15] > cb)
		                  if(p[offset1] > cb)
		                    goto is_a_corner;
		                  else
		                    if(p[offset8] > cb)
		                      if(p[offset9] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset6] > cb)
		                    if(p[offset7] > cb)
		                      if(p[offset8] > cb)
		                        if(p[offset9] > cb)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset5] > cb)
		                  if(p[offset6] > cb)
		                    if(p[offset7] > cb)
		                      if(p[offset8] > cb)
		                        if(p[offset9] > cb)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              if(p[offset1] > cb)
		                if(p[offset3] > cb)
		                  if(p[offset14] > cb)
		                    if(p[offset15] > cb)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else if(p[offset11] < c_b)
		        if(p[offset7] < c_b)
		          if(p[offset8] < c_b)
		            if(p[offset9] < c_b)
		              if(p[offset10] < c_b)
		                if(p[offset6] < c_b)
		                  if(p[offset5] < c_b)
		                    if(p[offset3] < c_b)
		                      goto is_a_corner;
		                    else
		                      if(p[offset12] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                  else
		                    if(p[offset12] < c_b)
		                      if(p[offset13] < c_b)
		                        if(p[offset14] < c_b)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset12] < c_b)
		                    if(p[offset13] < c_b)
		                      if(p[offset14] < c_b)
		                        if(p[offset15] < c_b)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		    else
		      if(p[offset11] > cb)
		        if(p[offset12] > cb)
		          if(p[offset13] > cb)
		            if(p[offset10] > cb)
		              if(p[offset14] > cb)
		                if(p[offset15] > cb)
		                  if(p[offset1] > cb)
		                    goto is_a_corner;
		                  else
		                    if(p[offset8] > cb)
		                      if(p[offset9] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset6] > cb)
		                    if(p[offset7] > cb)
		                      if(p[offset8] > cb)
		                        if(p[offset9] > cb)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset5] > cb)
		                  if(p[offset6] > cb)
		                    if(p[offset7] > cb)
		                      if(p[offset8] > cb)
		                        if(p[offset9] > cb)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              if(p[offset1] > cb)
		                if(p[offset3] > cb)
		                  if(p[offset14] > cb)
		                    if(p[offset15] > cb)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else if(p[offset11] < c_b)
		        if(p[offset7] < c_b)
		          if(p[offset8] < c_b)
		            if(p[offset9] < c_b)
		              if(p[offset10] < c_b)
		                if(p[offset12] < c_b)
		                  if(p[offset13] < c_b)
		                    if(p[offset6] < c_b)
		                      if(p[offset5] < c_b)
		                        goto is_a_corner;
		                      else
		                        if(p[offset14] < c_b)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                    else
		                      if(p[offset14] < c_b)
		                        if(p[offset15] < c_b)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		  else if(p[offset2] < c_b)
		    if(p[offset9] > cb)
		      if(p[offset10] > cb)
		        if(p[offset11] > cb)
		          if(p[offset8] > cb)
		            if(p[offset12] > cb)
		              if(p[offset13] > cb)
		                if(p[offset14] > cb)
		                  if(p[offset15] > cb)
		                    goto is_a_corner;
		                  else
		                    if(p[offset6] > cb)
		                      if(p[offset7] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset5] > cb)
		                    if(p[offset6] > cb)
		                      if(p[offset7] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset4] > cb)
		                  if(p[offset5] > cb)
		                    if(p[offset6] > cb)
		                      if(p[offset7] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              if(p[offset3] > cb)
		                if(p[offset4] > cb)
		                  if(p[offset5] > cb)
		                    if(p[offset6] > cb)
		                      if(p[offset7] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            if(p[offset1] > cb)
		              if(p[offset12] > cb)
		                if(p[offset13] > cb)
		                  if(p[offset14] > cb)
		                    if(p[offset15] > cb)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		    else if(p[offset9] < c_b)
		      if(p[offset7] < c_b)
		        if(p[offset8] < c_b)
		          if(p[offset6] < c_b)
		            if(p[offset5] < c_b)
		              if(p[offset4] < c_b)
		                if(p[offset3] < c_b)
		                  if(p[offset1] < c_b)
		                    goto is_a_corner;
		                  else
		                    if(p[offset10] < c_b)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset10] < c_b)
		                    if(p[offset11] < c_b)
		                      if(p[offset12] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset10] < c_b)
		                  if(p[offset11] < c_b)
		                    if(p[offset12] < c_b)
		                      if(p[offset13] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              if(p[offset10] < c_b)
		                if(p[offset11] < c_b)
		                  if(p[offset12] < c_b)
		                    if(p[offset13] < c_b)
		                      if(p[offset14] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            if(p[offset10] < c_b)
		              if(p[offset11] < c_b)
		                if(p[offset12] < c_b)
		                  if(p[offset13] < c_b)
		                    if(p[offset14] < c_b)
		                      if(p[offset15] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		    else
		      goto is_not_a_corner;
		  else
		    if(p[offset9] > cb)
		      if(p[offset10] > cb)
		        if(p[offset11] > cb)
		          if(p[offset8] > cb)
		            if(p[offset12] > cb)
		              if(p[offset13] > cb)
		                if(p[offset14] > cb)
		                  if(p[offset15] > cb)
		                    goto is_a_corner;
		                  else
		                    if(p[offset6] > cb)
		                      if(p[offset7] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset5] > cb)
		                    if(p[offset6] > cb)
		                      if(p[offset7] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset4] > cb)
		                  if(p[offset5] > cb)
		                    if(p[offset6] > cb)
		                      if(p[offset7] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              if(p[offset3] > cb)
		                if(p[offset4] > cb)
		                  if(p[offset5] > cb)
		                    if(p[offset6] > cb)
		                      if(p[offset7] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            if(p[offset1] > cb)
		              if(p[offset12] > cb)
		                if(p[offset13] > cb)
		                  if(p[offset14] > cb)
		                    if(p[offset15] > cb)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		    else if(p[offset9] < c_b)
		      if(p[offset7] < c_b)
		        if(p[offset8] < c_b)
		          if(p[offset10] < c_b)
		            if(p[offset11] < c_b)
		              if(p[offset6] < c_b)
		                if(p[offset5] < c_b)
		                  if(p[offset4] < c_b)
		                    if(p[offset3] < c_b)
		                      goto is_a_corner;
		                    else
		                      if(p[offset12] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                  else
		                    if(p[offset12] < c_b)
		                      if(p[offset13] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset12] < c_b)
		                    if(p[offset13] < c_b)
		                      if(p[offset14] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset12] < c_b)
		                  if(p[offset13] < c_b)
		                    if(p[offset14] < c_b)
		                      if(p[offset15] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		    else
		      goto is_not_a_corner;
		else if(p[offset0] < c_b)
		  if(p[offset2] > cb)
		    if(p[offset9] > cb)
		      if(p[offset7] > cb)
		        if(p[offset8] > cb)
		          if(p[offset6] > cb)
		            if(p[offset5] > cb)
		              if(p[offset4] > cb)
		                if(p[offset3] > cb)
		                  if(p[offset1] > cb)
		                    goto is_a_corner;
		                  else
		                    if(p[offset10] > cb)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset10] > cb)
		                    if(p[offset11] > cb)
		                      if(p[offset12] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset10] > cb)
		                  if(p[offset11] > cb)
		                    if(p[offset12] > cb)
		                      if(p[offset13] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              if(p[offset10] > cb)
		                if(p[offset11] > cb)
		                  if(p[offset12] > cb)
		                    if(p[offset13] > cb)
		                      if(p[offset14] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            if(p[offset10] > cb)
		              if(p[offset11] > cb)
		                if(p[offset12] > cb)
		                  if(p[offset13] > cb)
		                    if(p[offset14] > cb)
		                      if(p[offset15] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		    else if(p[offset9] < c_b)
		      if(p[offset10] < c_b)
		        if(p[offset11] < c_b)
		          if(p[offset8] < c_b)
		            if(p[offset12] < c_b)
		              if(p[offset13] < c_b)
		                if(p[offset14] < c_b)
		                  if(p[offset15] < c_b)
		                    goto is_a_corner;
		                  else
		                    if(p[offset6] < c_b)
		                      if(p[offset7] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset5] < c_b)
		                    if(p[offset6] < c_b)
		                      if(p[offset7] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset4] < c_b)
		                  if(p[offset5] < c_b)
		                    if(p[offset6] < c_b)
		                      if(p[offset7] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              if(p[offset3] < c_b)
		                if(p[offset4] < c_b)
		                  if(p[offset5] < c_b)
		                    if(p[offset6] < c_b)
		                      if(p[offset7] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            if(p[offset1] < c_b)
		              if(p[offset12] < c_b)
		                if(p[offset13] < c_b)
		                  if(p[offset14] < c_b)
		                    if(p[offset15] < c_b)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		    else
		      goto is_not_a_corner;
		  else if(p[offset2] < c_b)
		    if(p[offset4] > cb)
		      if(p[offset11] > cb)
		        if(p[offset7] > cb)
		          if(p[offset8] > cb)
		            if(p[offset9] > cb)
		              if(p[offset10] > cb)
		                if(p[offset6] > cb)
		                  if(p[offset5] > cb)
		                    if(p[offset3] > cb)
		                      goto is_a_corner;
		                    else
		                      if(p[offset12] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                  else
		                    if(p[offset12] > cb)
		                      if(p[offset13] > cb)
		                        if(p[offset14] > cb)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset12] > cb)
		                    if(p[offset13] > cb)
		                      if(p[offset14] > cb)
		                        if(p[offset15] > cb)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else if(p[offset11] < c_b)
		        if(p[offset12] < c_b)
		          if(p[offset13] < c_b)
		            if(p[offset10] < c_b)
		              if(p[offset14] < c_b)
		                if(p[offset15] < c_b)
		                  if(p[offset1] < c_b)
		                    goto is_a_corner;
		                  else
		                    if(p[offset8] < c_b)
		                      if(p[offset9] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset6] < c_b)
		                    if(p[offset7] < c_b)
		                      if(p[offset8] < c_b)
		                        if(p[offset9] < c_b)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset5] < c_b)
		                  if(p[offset6] < c_b)
		                    if(p[offset7] < c_b)
		                      if(p[offset8] < c_b)
		                        if(p[offset9] < c_b)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              if(p[offset1] < c_b)
		                if(p[offset3] < c_b)
		                  if(p[offset14] < c_b)
		                    if(p[offset15] < c_b)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		    else if(p[offset4] < c_b)
		      if(p[offset5] > cb)
		        if(p[offset12] > cb)
		          if(p[offset7] > cb)
		            if(p[offset8] > cb)
		              if(p[offset9] > cb)
		                if(p[offset10] > cb)
		                  if(p[offset11] > cb)
		                    if(p[offset13] > cb)
		                      if(p[offset6] > cb)
		                        goto is_a_corner;
		                      else
		                        if(p[offset14] > cb)
		                          if(p[offset15] > cb)
		                            goto is_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else if(p[offset12] < c_b)
		          if(p[offset13] < c_b)
		            if(p[offset14] < c_b)
		              if(p[offset15] < c_b)
		                if(p[offset1] < c_b)
		                  if(p[offset3] < c_b)
		                    goto is_a_corner;
		                  else
		                    if(p[offset10] < c_b)
		                      if(p[offset11] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset8] < c_b)
		                    if(p[offset9] < c_b)
		                      if(p[offset10] < c_b)
		                        if(p[offset11] < c_b)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset6] < c_b)
		                  if(p[offset7] < c_b)
		                    if(p[offset8] < c_b)
		                      if(p[offset9] < c_b)
		                        if(p[offset10] < c_b)
		                          if(p[offset11] < c_b)
		                            goto is_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else if(p[offset5] < c_b)
		        if(p[offset7] > cb)
		          if(p[offset14] > cb)
		            if(p[offset8] > cb)
		              if(p[offset9] > cb)
		                if(p[offset10] > cb)
		                  if(p[offset11] > cb)
		                    if(p[offset12] > cb)
		                      if(p[offset13] > cb)
		                        if(p[offset6] > cb)
		                          goto is_a_corner;
		                        else
		                          if(p[offset15] > cb)
		                            goto is_a_corner;
		                          else
		                            goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else if(p[offset14] < c_b)
		            if(p[offset15] < c_b)
		              if(p[offset1] < c_b)
		                if(p[offset3] < c_b)
		                  if(p[offset6] < c_b)
		                    goto is_a_corner;
		                  else
		                    if(p[offset13] < c_b)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset10] < c_b)
		                    if(p[offset11] < c_b)
		                      if(p[offset12] < c_b)
		                        if(p[offset13] < c_b)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset8] < c_b)
		                  if(p[offset9] < c_b)
		                    if(p[offset10] < c_b)
		                      if(p[offset11] < c_b)
		                        if(p[offset12] < c_b)
		                          if(p[offset13] < c_b)
		                            goto is_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else if(p[offset7] < c_b)
		          if(p[offset3] < c_b)
		            if(p[offset1] < c_b)
		              if(p[offset6] < c_b)
		                if(p[offset8] < c_b)
		                  goto is_a_corner;
		                else
		                  if(p[offset15] < c_b)
		                    goto is_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset13] < c_b)
		                  if(p[offset14] < c_b)
		                    if(p[offset15] < c_b)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              if(p[offset8] < c_b)
		                if(p[offset9] < c_b)
		                  if(p[offset10] < c_b)
		                    if(p[offset6] < c_b)
		                      goto is_a_corner;
		                    else
		                      if(p[offset11] < c_b)
		                        if(p[offset12] < c_b)
		                          if(p[offset13] < c_b)
		                            if(p[offset14] < c_b)
		                              if(p[offset15] < c_b)
		                                goto is_a_corner;
		                              else
		                                goto is_not_a_corner;
		                            else
		                              goto is_not_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            if(p[offset10] < c_b)
		              if(p[offset11] < c_b)
		                if(p[offset12] < c_b)
		                  if(p[offset8] < c_b)
		                    if(p[offset9] < c_b)
		                      if(p[offset6] < c_b)
		                        goto is_a_corner;
		                      else
		                        if(p[offset13] < c_b)
		                          if(p[offset14] < c_b)
		                            if(p[offset15] < c_b)
		                              goto is_a_corner;
		                            else
		                              goto is_not_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                    else
		                      if(p[offset1] < c_b)
		                        if(p[offset13] < c_b)
		                          if(p[offset14] < c_b)
		                            if(p[offset15] < c_b)
		                              goto is_a_corner;
		                            else
		                              goto is_not_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                  else
		                    if(p[offset1] < c_b)
		                      if(p[offset13] < c_b)
		                        if(p[offset14] < c_b)
		                          if(p[offset15] < c_b)
		                            goto is_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          if(p[offset14] < c_b)
		            if(p[offset15] < c_b)
		              if(p[offset1] < c_b)
		                if(p[offset3] < c_b)
		                  if(p[offset6] < c_b)
		                    goto is_a_corner;
		                  else
		                    if(p[offset13] < c_b)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset10] < c_b)
		                    if(p[offset11] < c_b)
		                      if(p[offset12] < c_b)
		                        if(p[offset13] < c_b)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset8] < c_b)
		                  if(p[offset9] < c_b)
		                    if(p[offset10] < c_b)
		                      if(p[offset11] < c_b)
		                        if(p[offset12] < c_b)
		                          if(p[offset13] < c_b)
		                            goto is_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		      else
		        if(p[offset12] > cb)
		          if(p[offset7] > cb)
		            if(p[offset8] > cb)
		              if(p[offset9] > cb)
		                if(p[offset10] > cb)
		                  if(p[offset11] > cb)
		                    if(p[offset13] > cb)
		                      if(p[offset14] > cb)
		                        if(p[offset6] > cb)
		                          goto is_a_corner;
		                        else
		                          if(p[offset15] > cb)
		                            goto is_a_corner;
		                          else
		                            goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else if(p[offset12] < c_b)
		          if(p[offset13] < c_b)
		            if(p[offset14] < c_b)
		              if(p[offset15] < c_b)
		                if(p[offset1] < c_b)
		                  if(p[offset3] < c_b)
		                    goto is_a_corner;
		                  else
		                    if(p[offset10] < c_b)
		                      if(p[offset11] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset8] < c_b)
		                    if(p[offset9] < c_b)
		                      if(p[offset10] < c_b)
		                        if(p[offset11] < c_b)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset6] < c_b)
		                  if(p[offset7] < c_b)
		                    if(p[offset8] < c_b)
		                      if(p[offset9] < c_b)
		                        if(p[offset10] < c_b)
		                          if(p[offset11] < c_b)
		                            goto is_a_corner;
		                          else
		                            goto is_not_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		    else
		      if(p[offset11] > cb)
		        if(p[offset7] > cb)
		          if(p[offset8] > cb)
		            if(p[offset9] > cb)
		              if(p[offset10] > cb)
		                if(p[offset12] > cb)
		                  if(p[offset13] > cb)
		                    if(p[offset6] > cb)
		                      if(p[offset5] > cb)
		                        goto is_a_corner;
		                      else
		                        if(p[offset14] > cb)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                    else
		                      if(p[offset14] > cb)
		                        if(p[offset15] > cb)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else if(p[offset11] < c_b)
		        if(p[offset12] < c_b)
		          if(p[offset13] < c_b)
		            if(p[offset10] < c_b)
		              if(p[offset14] < c_b)
		                if(p[offset15] < c_b)
		                  if(p[offset1] < c_b)
		                    goto is_a_corner;
		                  else
		                    if(p[offset8] < c_b)
		                      if(p[offset9] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset6] < c_b)
		                    if(p[offset7] < c_b)
		                      if(p[offset8] < c_b)
		                        if(p[offset9] < c_b)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset5] < c_b)
		                  if(p[offset6] < c_b)
		                    if(p[offset7] < c_b)
		                      if(p[offset8] < c_b)
		                        if(p[offset9] < c_b)
		                          goto is_a_corner;
		                        else
		                          goto is_not_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              if(p[offset1] < c_b)
		                if(p[offset3] < c_b)
		                  if(p[offset14] < c_b)
		                    if(p[offset15] < c_b)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		  else
		    if(p[offset9] > cb)
		      if(p[offset7] > cb)
		        if(p[offset8] > cb)
		          if(p[offset10] > cb)
		            if(p[offset11] > cb)
		              if(p[offset6] > cb)
		                if(p[offset5] > cb)
		                  if(p[offset4] > cb)
		                    if(p[offset3] > cb)
		                      goto is_a_corner;
		                    else
		                      if(p[offset12] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                  else
		                    if(p[offset12] > cb)
		                      if(p[offset13] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset12] > cb)
		                    if(p[offset13] > cb)
		                      if(p[offset14] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset12] > cb)
		                  if(p[offset13] > cb)
		                    if(p[offset14] > cb)
		                      if(p[offset15] > cb)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		    else if(p[offset9] < c_b)
		      if(p[offset10] < c_b)
		        if(p[offset11] < c_b)
		          if(p[offset8] < c_b)
		            if(p[offset12] < c_b)
		              if(p[offset13] < c_b)
		                if(p[offset14] < c_b)
		                  if(p[offset15] < c_b)
		                    goto is_a_corner;
		                  else
		                    if(p[offset6] < c_b)
		                      if(p[offset7] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset5] < c_b)
		                    if(p[offset6] < c_b)
		                      if(p[offset7] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset4] < c_b)
		                  if(p[offset5] < c_b)
		                    if(p[offset6] < c_b)
		                      if(p[offset7] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              if(p[offset3] < c_b)
		                if(p[offset4] < c_b)
		                  if(p[offset5] < c_b)
		                    if(p[offset6] < c_b)
		                      if(p[offset7] < c_b)
		                        goto is_a_corner;
		                      else
		                        goto is_not_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            if(p[offset1] < c_b)
		              if(p[offset12] < c_b)
		                if(p[offset13] < c_b)
		                  if(p[offset14] < c_b)
		                    if(p[offset15] < c_b)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		    else
		      goto is_not_a_corner;
		else
		  if(p[offset7] > cb)
		    if(p[offset8] > cb)
		      if(p[offset9] > cb)
		        if(p[offset6] > cb)
		          if(p[offset5] > cb)
		            if(p[offset4] > cb)
		              if(p[offset3] > cb)
		                if(p[offset2] > cb)
		                  if(p[offset1] > cb)
		                    goto is_a_corner;
		                  else
		                    if(p[offset10] > cb)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset10] > cb)
		                    if(p[offset11] > cb)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset10] > cb)
		                  if(p[offset11] > cb)
		                    if(p[offset12] > cb)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              if(p[offset10] > cb)
		                if(p[offset11] > cb)
		                  if(p[offset12] > cb)
		                    if(p[offset13] > cb)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            if(p[offset10] > cb)
		              if(p[offset11] > cb)
		                if(p[offset12] > cb)
		                  if(p[offset13] > cb)
		                    if(p[offset14] > cb)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          if(p[offset10] > cb)
		            if(p[offset11] > cb)
		              if(p[offset12] > cb)
		                if(p[offset13] > cb)
		                  if(p[offset14] > cb)
		                    if(p[offset15] > cb)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		    else
		      goto is_not_a_corner;
		  else if(p[offset7] < c_b)
		    if(p[offset8] < c_b)
		      if(p[offset9] < c_b)
		        if(p[offset6] < c_b)
		          if(p[offset5] < c_b)
		            if(p[offset4] < c_b)
		              if(p[offset3] < c_b)
		                if(p[offset2] < c_b)
		                  if(p[offset1] < c_b)
		                    goto is_a_corner;
		                  else
		                    if(p[offset10] < c_b)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                else
		                  if(p[offset10] < c_b)
		                    if(p[offset11] < c_b)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		              else
		                if(p[offset10] < c_b)
		                  if(p[offset11] < c_b)
		                    if(p[offset12] < c_b)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              if(p[offset10] < c_b)
		                if(p[offset11] < c_b)
		                  if(p[offset12] < c_b)
		                    if(p[offset13] < c_b)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            if(p[offset10] < c_b)
		              if(p[offset11] < c_b)
		                if(p[offset12] < c_b)
		                  if(p[offset13] < c_b)
		                    if(p[offset14] < c_b)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          if(p[offset10] < c_b)
		            if(p[offset11] < c_b)
		              if(p[offset12] < c_b)
		                if(p[offset13] < c_b)
		                  if(p[offset14] < c_b)
		                    if(p[offset15] < c_b)
		                      goto is_a_corner;
		                    else
		                      goto is_not_a_corner;
		                  else
		                    goto is_not_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		    else
		      goto is_not_a_corner;
		  else
		    goto is_not_a_corner;
		is_a_corner:
			bmin=b_test;
			goto end;
		
		is_not_a_corner:
			bmax=b_test;
			goto end;
		end:
		if(bmin == bmax - 1 || bmin == bmax)
			return bmin;
		b_test = (bmin + bmax) / 2;
	}
}
int fast5_corner_score(const byte* p, const int pixel[], int bstart)
{    
    int bmin = bstart;
    int bmax = 255;
    int b_test = (bmax + bmin)/2;
    int offset0, offset1, offset2, offset3, offset4, offset5, offset6, offset7;
    offset0=*p + pixel[0];
    offset1=*p + pixel[1];
    offset2=*p + pixel[2];
    offset3=*p + pixel[3];
    offset4=*p + pixel[4];
    offset5=*p + pixel[5];
    offset6=*p + pixel[6];
    offset7=*p + pixel[7];
    /*Compute the score using binary search*/
	while(1)
	{
		register const int cb = *p + b_test;
		register const int c_b = *p - b_test;
		if(p[offset0] > cb)
		  if(p[offset2] > cb)
		    if(p[offset3] > cb)
		      if(p[offset5] > cb)
		        if(p[offset1] > cb)
		          if(p[offset4] > cb)
		            goto is_a_corner;
		          else
		            if(p[offset7] > cb)
		              goto is_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          if(p[offset4] > cb)
		            if(p[offset6] > cb)
		              goto is_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		      else
		        if(p[offset1] > cb)
		          if(p[offset4] > cb)
		            goto is_a_corner;
		          else
		            if(p[offset7] > cb)
		              goto is_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		    else
		      if(p[offset7] > cb)
		        if(p[offset6] > cb)
		          if(p[offset5] > cb)
		            if(p[offset1] > cb)
		              goto is_a_corner;
		            else
		              if(p[offset4] > cb)
		                goto is_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            if(p[offset1] > cb)
		              goto is_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        if(p[offset5] < c_b)
		          if(p[offset3] < c_b)
		            if(p[offset7] < c_b)
		              if(p[offset4] < c_b)
		                if(p[offset6] < c_b)
		                  goto is_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		  else
		    if(p[offset5] > cb)
		      if(p[offset7] > cb)
		        if(p[offset6] > cb)
		          if(p[offset1] > cb)
		            goto is_a_corner;
		          else
		            if(p[offset4] > cb)
		              goto is_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		    else
		      if(p[offset5] < c_b)
		        if(p[offset3] < c_b)
		          if(p[offset2] < c_b)
		            if(p[offset1] < c_b)
		              if(p[offset4] < c_b)
		                goto is_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              if(p[offset4] < c_b)
		                if(p[offset6] < c_b)
		                  goto is_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            if(p[offset7] < c_b)
		              if(p[offset4] < c_b)
		                if(p[offset6] < c_b)
		                  goto is_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		else if(p[offset0] < c_b)
		  if(p[offset2] < c_b)
		    if(p[offset7] > cb)
		      if(p[offset3] < c_b)
		        if(p[offset5] < c_b)
		          if(p[offset1] < c_b)
		            if(p[offset4] < c_b)
		              goto is_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            if(p[offset4] < c_b)
		              if(p[offset6] < c_b)
		                goto is_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          if(p[offset1] < c_b)
		            if(p[offset4] < c_b)
		              goto is_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		      else
		        if(p[offset5] > cb)
		          if(p[offset3] > cb)
		            if(p[offset4] > cb)
		              if(p[offset6] > cb)
		                goto is_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		    else
		      if(p[offset7] < c_b)
		        if(p[offset3] < c_b)
		          if(p[offset5] < c_b)
		            if(p[offset1] < c_b)
		              goto is_a_corner;
		            else
		              if(p[offset4] < c_b)
		                if(p[offset6] < c_b)
		                  goto is_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            if(p[offset1] < c_b)
		              goto is_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          if(p[offset6] < c_b)
		            if(p[offset5] < c_b)
		              if(p[offset1] < c_b)
		                goto is_a_corner;
		              else
		                if(p[offset4] < c_b)
		                  goto is_a_corner;
		                else
		                  goto is_not_a_corner;
		            else
		              if(p[offset1] < c_b)
		                goto is_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		      else
		        if(p[offset3] < c_b)
		          if(p[offset5] < c_b)
		            if(p[offset1] < c_b)
		              if(p[offset4] < c_b)
		                goto is_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              if(p[offset4] < c_b)
		                if(p[offset6] < c_b)
		                  goto is_a_corner;
		                else
		                  goto is_not_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            if(p[offset1] < c_b)
		              if(p[offset4] < c_b)
		                goto is_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		  else
		    if(p[offset5] > cb)
		      if(p[offset3] > cb)
		        if(p[offset2] > cb)
		          if(p[offset1] > cb)
		            if(p[offset4] > cb)
		              goto is_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            if(p[offset4] > cb)
		              if(p[offset6] > cb)
		                goto is_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          if(p[offset7] > cb)
		            if(p[offset4] > cb)
		              if(p[offset6] > cb)
		                goto is_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		    else
		      if(p[offset5] < c_b)
		        if(p[offset7] < c_b)
		          if(p[offset6] < c_b)
		            if(p[offset1] < c_b)
		              goto is_a_corner;
		            else
		              if(p[offset4] < c_b)
		                goto is_a_corner;
		              else
		                goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		else
		  if(p[offset3] > cb)
		    if(p[offset5] > cb)
		      if(p[offset2] > cb)
		        if(p[offset1] > cb)
		          if(p[offset4] > cb)
		            goto is_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          if(p[offset4] > cb)
		            if(p[offset6] > cb)
		              goto is_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		      else
		        if(p[offset7] > cb)
		          if(p[offset4] > cb)
		            if(p[offset6] > cb)
		              goto is_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		        else
		          goto is_not_a_corner;
		    else
		      goto is_not_a_corner;
		  else
		    if(p[offset3] < c_b)
		      if(p[offset5] < c_b)
		        if(p[offset2] < c_b)
		          if(p[offset1] < c_b)
		            if(p[offset4] < c_b)
		              goto is_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            if(p[offset4] < c_b)
		              if(p[offset6] < c_b)
		                goto is_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		        else
		          if(p[offset7] < c_b)
		            if(p[offset4] < c_b)
		              if(p[offset6] < c_b)
		                goto is_a_corner;
		              else
		                goto is_not_a_corner;
		            else
		              goto is_not_a_corner;
		          else
		            goto is_not_a_corner;
		      else
		        goto is_not_a_corner;
		    else
		      goto is_not_a_corner;
		is_a_corner:
			bmin=b_test;
			goto end;
		is_not_a_corner:
			bmax=b_test;
			goto end;
		end:
		if(bmin == bmax - 1 || bmin == bmax)
			return bmin;
		b_test = (bmin + bmax) / 2;
	}
}
static void make_offsets(int pixel[], int row_stride)
{
				pixel[0]=(-3)+(0)*row_stride;
//				printf("%d\n", pixel[0]);
				pixel[1]=(-3)+(-1)*row_stride;
				pixel[2]=(-2)+(-2)*row_stride;
				pixel[3]=(-1)+(-3)*row_stride;
				pixel[4]=(0)+(-3)*row_stride;
				pixel[5]=(1)+(-3)*row_stride;
				pixel[6]=(2)+(-2)*row_stride;
				pixel[7]=(3)+(-1)*row_stride;
				pixel[8]=(3)+(0)*row_stride;
				pixel[9]=(3)+(1)*row_stride;
				pixel[10]=(2)+(2)*row_stride;
				pixel[11]=(1)+(3)*row_stride;
				pixel[12]=(0)+(3)*row_stride;
				pixel[13]=(-1)+(3)*row_stride;
				pixel[14]=(-2)+(2)*row_stride;
				pixel[15]=(-3)+(1)*row_stride;
				    		
}
static void make_offsets5(int pixel[], int row_stride)
{
			pixel[0]=(-1)+(0)*row_stride;
			pixel[1]=(-1)+(-1)*row_stride;
			pixel[2]=(0)+(-1)*row_stride;
			pixel[3]=(1)+(-1)*row_stride;
			pixel[4]=(1)+(0)*row_stride;
			pixel[5]=(1)+(1)*row_stride;
			pixel[6]=(0)+(1)*row_stride;
			pixel[7]=(-1)+(1)*row_stride;     		
}
void fast9_score(const byte* i, int stride, xy* corners, int num_corners, int b, int height, int **scores, int p, int *** scoremat)
{	
	int n, f;
	int pixel[16];
//	make_offsets(pixel, stride);
	
	
	
    for(n=0; n < num_corners; n++)
    {
    	if(whatever== 0)
        	printf("\nvalue: %d %d %d %d\n", corners[n].x,corners[n].y,stride, *(i+corners[n].x*stride+corners[n].y));
        scores[corners[n].x][corners[n].y] = fast9_corner_score(i + corners[n].x*stride + corners[n].y, pixel, b, stride);
        
	    scoremat[p][corners[n].x][corners[n].y]= fast9_corner_score(i + corners[n].x*stride + corners[n].y, pixel, b, stride);
//	    printf("%d %d\n", corners[n].x, corners[n].y);
	}
//	printf("hello\n");
}
void fast5_score(const byte* i, int stride, xy* corners, int num_corners, int b, int height, int **scores5, int p, int *** scoremat5)
{	
	int n;
	int pixel[8];
	make_offsets5(pixel, stride);
	
    for(n=0; n < num_corners; n++)
    {
        scores5[corners[n].x][corners[n].y] = fast5_corner_score(i + corners[n].x*stride + corners[n].y, pixel, b);
	    scoremat5[p][corners[n].x][corners[n].y]= fast5_corner_score(i + corners[n].x*stride + corners[n].y, pixel, b);
	    
	}
	
}
xy* fast9_detect(const byte* im, int xsize, int ysize, int stride, int b, int* ret_num_corners)
{
	int total = 0;
	
	
//	int pixel[16];
	int x, y;
	int offset0, offset1, offset2, offset3, offset4, offset5, offset6, offset7, offset8, offset9, offset10, offset11, offset12, offset13, offset14, offset15;
//	int width=xsize;
			int		s_offset0=(-3)+(0)*stride;
			int 	s_offset1=(-3)+(-1)*stride;
			int 	s_offset2=(-2)+(-2)*stride;
			int 	s_offset3=(-1)+(-3)*stride;
			int 	s_offset4=(0)+(-3)*stride;
			int 	s_offset5=(1)+(-3)*stride;
			int 	s_offset6=(2)+(-2)*stride;
			int 	s_offset7=(3)+(-1)*stride;
			int 	s_offset8=(3)+(0)*stride;
			int 	s_offset9=(3)+(1)*stride;
			int 	s_offset10=(2)+(2)*stride;
			int 	s_offset11=(1)+(3)*stride;
			int 	s_offset12=(0)+(3)*stride;
			int 	s_offset13=(-1)+(3)*stride;
			int 	s_offset14=(-2)+(2)*stride;
			int 	s_offset15=(-3)+(1)*stride;
	offset0=s_offset0;
    offset1=s_offset1;
    offset2=s_offset2;
    offset3=s_offset3;
    offset4=s_offset4;
    offset5=s_offset5;
    offset6=s_offset6;
    offset7=s_offset7;
    offset8=s_offset8;
    offset9=s_offset9;
    offset10=s_offset10;
    offset11=s_offset11;
    offset12=s_offset12;
    offset13=s_offset13;
    offset14=s_offset14;
    offset15=s_offset15;
    
			
	register int xsizeB=xsize - 3;
	register int ysizeB=ysize - 4;
	h = (xy*)malloc(sizeof(xy)*nExpectedCorners);
//printf("hello!");
	for(x=3; x < xsizeB; x++)			
	{										
		y=2;								
		while(1)							
		{									
			y++;			
			if(y>ysizeB)	
				break; 
			else
			{
				
			register const byte* const p = im + x*stride + y;
			
			register const int cb = *p + b;
			register const int c_b = *p - b;
			 
				
				if(p[offset0] > cb)
				  if(p[offset2] > cb)
					if(p[offset4] > cb)
					  if(p[offset5] > cb)
						if(p[offset7] > cb)
						  if(p[offset3] > cb)
							if(p[offset1] > cb)
							  if(p[offset6] > cb)
								if(p[offset8] > cb)
								  {}
								else
								  if(p[offset15] > cb)
									{}
								  else
									continue;
							  else
								if(p[offset13] > cb)
								  if(p[offset14] > cb)
									if(p[offset15] > cb)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  if(p[offset8] > cb)
								if(p[offset9] > cb)
								  if(p[offset10] > cb)
									if(p[offset6] > cb)
									  {}
									else
									  if(p[offset11] > cb)
										if(p[offset12] > cb)
										  if(p[offset13] > cb)
											if(p[offset14] > cb)
											  if(p[offset15] > cb)
												{}
											  else
												continue;
											else
											  continue;
										  else
											continue;
										else
										  continue;
									  else
										continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
						  else
							if(p[offset10] > cb)
							  if(p[offset11] > cb)
								if(p[offset12] > cb)
								  if(p[offset8] > cb)
									if(p[offset9] > cb)
									  if(p[offset6] > cb)
										{}
									  else
										if(p[offset13] > cb)
										  if(p[offset14] > cb)
											if(p[offset15] > cb)
											  {}
											else
											  continue;
										  else
											continue;
										else
										  continue;
									else
									  if(p[offset1] > cb)
										if(p[offset13] > cb)
										  if(p[offset14] > cb)
											if(p[offset15] > cb)
											  {}
											else
											  continue;
										  else
											continue;
										else
										  continue;
									  else
										continue;
								  else
									if(p[offset1] > cb)
									  if(p[offset13] > cb)
										if(p[offset14] > cb)
										  if(p[offset15] > cb)
											{}
										  else
											continue;
										else
										  continue;
									  else
										continue;
									else
									  continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						else if(p[offset7] < c_b)
						  if(p[offset14] > cb)
							if(p[offset15] > cb)
							  if(p[offset1] > cb)
								if(p[offset3] > cb)
								  if(p[offset6] > cb)
									{}
								  else
									if(p[offset13] > cb)
									  {}
									else
									  continue;
								else
								  if(p[offset10] > cb)
									if(p[offset11] > cb)
									  if(p[offset12] > cb)
										if(p[offset13] > cb)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset8] > cb)
								  if(p[offset9] > cb)
									if(p[offset10] > cb)
									  if(p[offset11] > cb)
										if(p[offset12] > cb)
										  if(p[offset13] > cb)
											{}
										  else
											continue;
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  continue;
						  else if(p[offset14] < c_b)
							if(p[offset8] < c_b)
							  if(p[offset9] < c_b)
								if(p[offset10] < c_b)
								  if(p[offset11] < c_b)
									if(p[offset12] < c_b)
									  if(p[offset13] < c_b)
										if(p[offset6] < c_b)
										  {}
										else
										  if(p[offset15] < c_b)
											{}
										  else
											continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						  else
							continue;
						else
						  if(p[offset14] > cb)
							if(p[offset15] > cb)
							  if(p[offset1] > cb)
								if(p[offset3] > cb)
								  if(p[offset6] > cb)
									{}
								  else
									if(p[offset13] > cb)
									  {}
									else
									  continue;
								else
								  if(p[offset10] > cb)
									if(p[offset11] > cb)
									  if(p[offset12] > cb)
										if(p[offset13] > cb)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset8] > cb)
								  if(p[offset9] > cb)
									if(p[offset10] > cb)
									  if(p[offset11] > cb)
										if(p[offset12] > cb)
										  if(p[offset13] > cb)
											{}
										  else
											continue;
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  continue;
						  else
							continue;
					  else if(p[offset5] < c_b)
						if(p[offset12] > cb)
						  if(p[offset13] > cb)
							if(p[offset14] > cb)
							  if(p[offset15] > cb)
								if(p[offset1] > cb)
								  if(p[offset3] > cb)
									{}
								  else
									if(p[offset10] > cb)
									  if(p[offset11] > cb)
										{}
									  else
										continue;
									else
									  continue;
								else
								  if(p[offset8] > cb)
									if(p[offset9] > cb)
									  if(p[offset10] > cb)
										if(p[offset11] > cb)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset6] > cb)
								  if(p[offset7] > cb)
									if(p[offset8] > cb)
									  if(p[offset9] > cb)
										if(p[offset10] > cb)
										  if(p[offset11] > cb)
											{}
										  else
											continue;
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  continue;
						  else
							continue;
						else if(p[offset12] < c_b)
						  if(p[offset7] < c_b)
							if(p[offset8] < c_b)
							  if(p[offset9] < c_b)
								if(p[offset10] < c_b)
								  if(p[offset11] < c_b)
									if(p[offset13] < c_b)
									  if(p[offset6] < c_b)
										{}
									  else
										if(p[offset14] < c_b)
										  if(p[offset15] < c_b)
											{}
										  else
											continue;
										else
										  continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						  else
							continue;
						else
						  continue;
					  else
						if(p[offset12] > cb)
						  if(p[offset13] > cb)
							if(p[offset14] > cb)
							  if(p[offset15] > cb)
								if(p[offset1] > cb)
								  if(p[offset3] > cb)
									{}
								  else
									if(p[offset10] > cb)
									  if(p[offset11] > cb)
										{}
									  else
										continue;
									else
									  continue;
								else
								  if(p[offset8] > cb)
									if(p[offset9] > cb)
									  if(p[offset10] > cb)
										if(p[offset11] > cb)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset6] > cb)
								  if(p[offset7] > cb)
									if(p[offset8] > cb)
									  if(p[offset9] > cb)
										if(p[offset10] > cb)
										  if(p[offset11] > cb)
											{}
										  else
											continue;
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  continue;
						  else
							continue;
						else if(p[offset12] < c_b)
						  if(p[offset7] < c_b)
							if(p[offset8] < c_b)
							  if(p[offset9] < c_b)
								if(p[offset10] < c_b)
								  if(p[offset11] < c_b)
									if(p[offset13] < c_b)
									  if(p[offset14] < c_b)
										if(p[offset6] < c_b)
										  {}
										else
										  if(p[offset15] < c_b)
											{}
										  else
											continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						  else
							continue;
						else
						  continue;
					else if(p[offset4] < c_b)
					  if(p[offset11] > cb)
						if(p[offset12] > cb)
						  if(p[offset13] > cb)
							if(p[offset10] > cb)
							  if(p[offset14] > cb)
								if(p[offset15] > cb)
								  if(p[offset1] > cb)
									{}
								  else
									if(p[offset8] > cb)
									  if(p[offset9] > cb)
										{}
									  else
										continue;
									else
									  continue;
								else
								  if(p[offset6] > cb)
									if(p[offset7] > cb)
									  if(p[offset8] > cb)
										if(p[offset9] > cb)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset5] > cb)
								  if(p[offset6] > cb)
									if(p[offset7] > cb)
									  if(p[offset8] > cb)
										if(p[offset9] > cb)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  if(p[offset1] > cb)
								if(p[offset3] > cb)
								  if(p[offset14] > cb)
									if(p[offset15] > cb)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
						  else
							continue;
						else
						  continue;
					  else if(p[offset11] < c_b)
						if(p[offset7] < c_b)
						  if(p[offset8] < c_b)
							if(p[offset9] < c_b)
							  if(p[offset10] < c_b)
								if(p[offset6] < c_b)
								  if(p[offset5] < c_b)
									if(p[offset3] < c_b)
									  {}
									else
									  if(p[offset12] < c_b)
										{}
									  else
										continue;
								  else
									if(p[offset12] < c_b)
									  if(p[offset13] < c_b)
										if(p[offset14] < c_b)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								else
								  if(p[offset12] < c_b)
									if(p[offset13] < c_b)
									  if(p[offset14] < c_b)
										if(p[offset15] < c_b)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								continue;
							else
							  continue;
						  else
							continue;
						else
						  continue;
					  else
						continue;
					else
					  if(p[offset11] > cb)
						if(p[offset12] > cb)
						  if(p[offset13] > cb)
							if(p[offset10] > cb)
							  if(p[offset14] > cb)
								if(p[offset15] > cb)
								  if(p[offset1] > cb)
									{}
								  else
									if(p[offset8] > cb)
									  if(p[offset9] > cb)
										{}
									  else
										continue;
									else
									  continue;
								else
								  if(p[offset6] > cb)
									if(p[offset7] > cb)
									  if(p[offset8] > cb)
										if(p[offset9] > cb)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset5] > cb)
								  if(p[offset6] > cb)
									if(p[offset7] > cb)
									  if(p[offset8] > cb)
										if(p[offset9] > cb)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  if(p[offset1] > cb)
								if(p[offset3] > cb)
								  if(p[offset14] > cb)
									if(p[offset15] > cb)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
						  else
							continue;
						else
						  continue;
					  else if(p[offset11] < c_b)
						if(p[offset7] < c_b)
						  if(p[offset8] < c_b)
							if(p[offset9] < c_b)
							  if(p[offset10] < c_b)
								if(p[offset12] < c_b)
								  if(p[offset13] < c_b)
									if(p[offset6] < c_b)
									  if(p[offset5] < c_b)
										{}
									  else
										if(p[offset14] < c_b)
										  {}
										else
										  continue;
									else
									  if(p[offset14] < c_b)
										if(p[offset15] < c_b)
										  {}
										else
										  continue;
									  else
										continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						  else
							continue;
						else
						  continue;
					  else
						continue;
				  else if(p[offset2] < c_b)
					if(p[offset9] > cb)
					  if(p[offset10] > cb)
						if(p[offset11] > cb)
						  if(p[offset8] > cb)
							if(p[offset12] > cb)
							  if(p[offset13] > cb)
								if(p[offset14] > cb)
								  if(p[offset15] > cb)
									{}
								  else
									if(p[offset6] > cb)
									  if(p[offset7] > cb)
										{}
									  else
										continue;
									else
									  continue;
								else
								  if(p[offset5] > cb)
									if(p[offset6] > cb)
									  if(p[offset7] > cb)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset4] > cb)
								  if(p[offset5] > cb)
									if(p[offset6] > cb)
									  if(p[offset7] > cb)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  if(p[offset3] > cb)
								if(p[offset4] > cb)
								  if(p[offset5] > cb)
									if(p[offset6] > cb)
									  if(p[offset7] > cb)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
						  else
							if(p[offset1] > cb)
							  if(p[offset12] > cb)
								if(p[offset13] > cb)
								  if(p[offset14] > cb)
									if(p[offset15] > cb)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						else
						  continue;
					  else
						continue;
					else if(p[offset9] < c_b)
					  if(p[offset7] < c_b)
						if(p[offset8] < c_b)
						  if(p[offset6] < c_b)
							if(p[offset5] < c_b)
							  if(p[offset4] < c_b)
								if(p[offset3] < c_b)
								  if(p[offset1] < c_b)
									{}
								  else
									if(p[offset10] < c_b)
									  {}
									else
									  continue;
								else
								  if(p[offset10] < c_b)
									if(p[offset11] < c_b)
									  if(p[offset12] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset10] < c_b)
								  if(p[offset11] < c_b)
									if(p[offset12] < c_b)
									  if(p[offset13] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  if(p[offset10] < c_b)
								if(p[offset11] < c_b)
								  if(p[offset12] < c_b)
									if(p[offset13] < c_b)
									  if(p[offset14] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
						  else
							if(p[offset10] < c_b)
							  if(p[offset11] < c_b)
								if(p[offset12] < c_b)
								  if(p[offset13] < c_b)
									if(p[offset14] < c_b)
									  if(p[offset15] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						else
						  continue;
					  else
						continue;
					else
					  continue;
				  else
					if(p[offset9] > cb)
					  if(p[offset10] > cb)
						if(p[offset11] > cb)
						  if(p[offset8] > cb)
							if(p[offset12] > cb)
							  if(p[offset13] > cb)
								if(p[offset14] > cb)
								  if(p[offset15] > cb)
									{}
								  else
									if(p[offset6] > cb)
									  if(p[offset7] > cb)
										{}
									  else
										continue;
									else
									  continue;
								else
								  if(p[offset5] > cb)
									if(p[offset6] > cb)
									  if(p[offset7] > cb)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset4] > cb)
								  if(p[offset5] > cb)
									if(p[offset6] > cb)
									  if(p[offset7] > cb)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  if(p[offset3] > cb)
								if(p[offset4] > cb)
								  if(p[offset5] > cb)
									if(p[offset6] > cb)
									  if(p[offset7] > cb)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
						  else
							if(p[offset1] > cb)
							  if(p[offset12] > cb)
								if(p[offset13] > cb)
								  if(p[offset14] > cb)
									if(p[offset15] > cb)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						else
						  continue;
					  else
						continue;
					else if(p[offset9] < c_b)
					  if(p[offset7] < c_b)
						if(p[offset8] < c_b)
						  if(p[offset10] < c_b)
							if(p[offset11] < c_b)
							  if(p[offset6] < c_b)
								if(p[offset5] < c_b)
								  if(p[offset4] < c_b)
									if(p[offset3] < c_b)
									  {}
									else
									  if(p[offset12] < c_b)
										{}
									  else
										continue;
								  else
									if(p[offset12] < c_b)
									  if(p[offset13] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								else
								  if(p[offset12] < c_b)
									if(p[offset13] < c_b)
									  if(p[offset14] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset12] < c_b)
								  if(p[offset13] < c_b)
									if(p[offset14] < c_b)
									  if(p[offset15] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  continue;
						  else
							continue;
						else
						  continue;
					  else
						continue;
					else
					  continue;
				else if(p[offset0] < c_b)
				  if(p[offset2] > cb)
					if(p[offset9] > cb)
					  if(p[offset7] > cb)
						if(p[offset8] > cb)
						  if(p[offset6] > cb)
							if(p[offset5] > cb)
							  if(p[offset4] > cb)
								if(p[offset3] > cb)
								  if(p[offset1] > cb)
									{}
								  else
									if(p[offset10] > cb)
									  {}
									else
									  continue;
								else
								  if(p[offset10] > cb)
									if(p[offset11] > cb)
									  if(p[offset12] > cb)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset10] > cb)
								  if(p[offset11] > cb)
									if(p[offset12] > cb)
									  if(p[offset13] > cb)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  if(p[offset10] > cb)
								if(p[offset11] > cb)
								  if(p[offset12] > cb)
									if(p[offset13] > cb)
									  if(p[offset14] > cb)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
						  else
							if(p[offset10] > cb)
							  if(p[offset11] > cb)
								if(p[offset12] > cb)
								  if(p[offset13] > cb)
									if(p[offset14] > cb)
									  if(p[offset15] > cb)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						else
						  continue;
					  else
						continue;
					else if(p[offset9] < c_b)
					  if(p[offset10] < c_b)
						if(p[offset11] < c_b)
						  if(p[offset8] < c_b)
							if(p[offset12] < c_b)
							  if(p[offset13] < c_b)
								if(p[offset14] < c_b)
								  if(p[offset15] < c_b)
									{}
								  else
									if(p[offset6] < c_b)
									  if(p[offset7] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								else
								  if(p[offset5] < c_b)
									if(p[offset6] < c_b)
									  if(p[offset7] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset4] < c_b)
								  if(p[offset5] < c_b)
									if(p[offset6] < c_b)
									  if(p[offset7] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  if(p[offset3] < c_b)
								if(p[offset4] < c_b)
								  if(p[offset5] < c_b)
									if(p[offset6] < c_b)
									  if(p[offset7] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
						  else
							if(p[offset1] < c_b)
							  if(p[offset12] < c_b)
								if(p[offset13] < c_b)
								  if(p[offset14] < c_b)
									if(p[offset15] < c_b)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						else
						  continue;
					  else
						continue;
					else
					  continue;
				  else if(p[offset2] < c_b)
					if(p[offset4] > cb)
					  if(p[offset11] > cb)
						if(p[offset7] > cb)
						  if(p[offset8] > cb)
							if(p[offset9] > cb)
							  if(p[offset10] > cb)
								if(p[offset6] > cb)
								  if(p[offset5] > cb)
									if(p[offset3] > cb)
									  {}
									else
									  if(p[offset12] > cb)
										{}
									  else
										continue;
								  else
									if(p[offset12] > cb)
									  if(p[offset13] > cb)
										if(p[offset14] > cb)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								else
								  if(p[offset12] > cb)
									if(p[offset13] > cb)
									  if(p[offset14] > cb)
										if(p[offset15] > cb)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								continue;
							else
							  continue;
						  else
							continue;
						else
						  continue;
					  else if(p[offset11] < c_b)
						if(p[offset12] < c_b)
						  if(p[offset13] < c_b)
							if(p[offset10] < c_b)
							  if(p[offset14] < c_b)
								if(p[offset15] < c_b)
								  if(p[offset1] < c_b)
									{}
								  else
									if(p[offset8] < c_b)
									  if(p[offset9] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								else
								  if(p[offset6] < c_b)
									if(p[offset7] < c_b)
									  if(p[offset8] < c_b)
										if(p[offset9] < c_b)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset5] < c_b)
								  if(p[offset6] < c_b)
									if(p[offset7] < c_b)
									  if(p[offset8] < c_b)
										if(p[offset9] < c_b)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  if(p[offset1] < c_b)
								if(p[offset3] < c_b)
								  if(p[offset14] < c_b)
									if(p[offset15] < c_b)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
						  else
							continue;
						else
						  continue;
					  else
						continue;
					else if(p[offset4] < c_b)
					  if(p[offset5] > cb)
						if(p[offset12] > cb)
						  if(p[offset7] > cb)
							if(p[offset8] > cb)
							  if(p[offset9] > cb)
								if(p[offset10] > cb)
								  if(p[offset11] > cb)
									if(p[offset13] > cb)
									  if(p[offset6] > cb)
										{}
									  else
										if(p[offset14] > cb)
										  if(p[offset15] > cb)
											{}
										  else
											continue;
										else
										  continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						  else
							continue;
						else if(p[offset12] < c_b)
						  if(p[offset13] < c_b)
							if(p[offset14] < c_b)
							  if(p[offset15] < c_b)
								if(p[offset1] < c_b)
								  if(p[offset3] < c_b)
									{}
								  else
									if(p[offset10] < c_b)
									  if(p[offset11] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								else
								  if(p[offset8] < c_b)
									if(p[offset9] < c_b)
									  if(p[offset10] < c_b)
										if(p[offset11] < c_b)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset6] < c_b)
								  if(p[offset7] < c_b)
									if(p[offset8] < c_b)
									  if(p[offset9] < c_b)
										if(p[offset10] < c_b)
										  if(p[offset11] < c_b)
											{}
										  else
											continue;
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  continue;
						  else
							continue;
						else
						  continue;
					  else if(p[offset5] < c_b)
						if(p[offset7] > cb)
						  if(p[offset14] > cb)
							if(p[offset8] > cb)
							  if(p[offset9] > cb)
								if(p[offset10] > cb)
								  if(p[offset11] > cb)
									if(p[offset12] > cb)
									  if(p[offset13] > cb)
										if(p[offset6] > cb)
										  {}
										else
										  if(p[offset15] > cb)
											{}
										  else
											continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						  else if(p[offset14] < c_b)
							if(p[offset15] < c_b)
							  if(p[offset1] < c_b)
								if(p[offset3] < c_b)
								  if(p[offset6] < c_b)
									{}
								  else
									if(p[offset13] < c_b)
									  {}
									else
									  continue;
								else
								  if(p[offset10] < c_b)
									if(p[offset11] < c_b)
									  if(p[offset12] < c_b)
										if(p[offset13] < c_b)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset8] < c_b)
								  if(p[offset9] < c_b)
									if(p[offset10] < c_b)
									  if(p[offset11] < c_b)
										if(p[offset12] < c_b)
										  if(p[offset13] < c_b)
											{}
										  else
											continue;
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  continue;
						  else
							continue;
						else if(p[offset7] < c_b)
						  if(p[offset3] < c_b)
							if(p[offset1] < c_b)
							  if(p[offset6] < c_b)
								if(p[offset8] < c_b)
								  {}
								else
								  if(p[offset15] < c_b)
									{}
								  else
									continue;
							  else
								if(p[offset13] < c_b)
								  if(p[offset14] < c_b)
									if(p[offset15] < c_b)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  if(p[offset8] < c_b)
								if(p[offset9] < c_b)
								  if(p[offset10] < c_b)
									if(p[offset6] < c_b)
									  {}
									else
									  if(p[offset11] < c_b)
										if(p[offset12] < c_b)
										  if(p[offset13] < c_b)
											if(p[offset14] < c_b)
											  if(p[offset15] < c_b)
												{}
											  else
												continue;
											else
											  continue;
										  else
											continue;
										else
										  continue;
									  else
										continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
						  else
							if(p[offset10] < c_b)
							  if(p[offset11] < c_b)
								if(p[offset12] < c_b)
								  if(p[offset8] < c_b)
									if(p[offset9] < c_b)
									  if(p[offset6] < c_b)
										{}
									  else
										if(p[offset13] < c_b)
										  if(p[offset14] < c_b)
											if(p[offset15] < c_b)
											  {}
											else
											  continue;
										  else
											continue;
										else
										  continue;
									else
									  if(p[offset1] < c_b)
										if(p[offset13] < c_b)
										  if(p[offset14] < c_b)
											if(p[offset15] < c_b)
											  {}
											else
											  continue;
										  else
											continue;
										else
										  continue;
									  else
										continue;
								  else
									if(p[offset1] < c_b)
									  if(p[offset13] < c_b)
										if(p[offset14] < c_b)
										  if(p[offset15] < c_b)
											{}
										  else
											continue;
										else
										  continue;
									  else
										continue;
									else
									  continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						else
						  if(p[offset14] < c_b)
							if(p[offset15] < c_b)
							  if(p[offset1] < c_b)
								if(p[offset3] < c_b)
								  if(p[offset6] < c_b)
									{}
								  else
									if(p[offset13] < c_b)
									  {}
									else
									  continue;
								else
								  if(p[offset10] < c_b)
									if(p[offset11] < c_b)
									  if(p[offset12] < c_b)
										if(p[offset13] < c_b)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset8] < c_b)
								  if(p[offset9] < c_b)
									if(p[offset10] < c_b)
									  if(p[offset11] < c_b)
										if(p[offset12] < c_b)
										  if(p[offset13] < c_b)
											{}
										  else
											continue;
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  continue;
						  else
							continue;
					  else
						if(p[offset12] > cb)
						  if(p[offset7] > cb)
							if(p[offset8] > cb)
							  if(p[offset9] > cb)
								if(p[offset10] > cb)
								  if(p[offset11] > cb)
									if(p[offset13] > cb)
									  if(p[offset14] > cb)
										if(p[offset6] > cb)
										  {}
										else
										  if(p[offset15] > cb)
											{}
										  else
											continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						  else
							continue;
						else if(p[offset12] < c_b)
						  if(p[offset13] < c_b)
							if(p[offset14] < c_b)
							  if(p[offset15] < c_b)
								if(p[offset1] < c_b)
								  if(p[offset3] < c_b)
									{}
								  else
									if(p[offset10] < c_b)
									  if(p[offset11] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								else
								  if(p[offset8] < c_b)
									if(p[offset9] < c_b)
									  if(p[offset10] < c_b)
										if(p[offset11] < c_b)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset6] < c_b)
								  if(p[offset7] < c_b)
									if(p[offset8] < c_b)
									  if(p[offset9] < c_b)
										if(p[offset10] < c_b)
										  if(p[offset11] < c_b)
											{}
										  else
											continue;
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  continue;
						  else
							continue;
						else
						  continue;
					else
					  if(p[offset11] > cb)
						if(p[offset7] > cb)
						  if(p[offset8] > cb)
							if(p[offset9] > cb)
							  if(p[offset10] > cb)
								if(p[offset12] > cb)
								  if(p[offset13] > cb)
									if(p[offset6] > cb)
									  if(p[offset5] > cb)
										{}
									  else
										if(p[offset14] > cb)
										  {}
										else
										  continue;
									else
									  if(p[offset14] > cb)
										if(p[offset15] > cb)
										  {}
										else
										  continue;
									  else
										continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						  else
							continue;
						else
						  continue;
					  else if(p[offset11] < c_b)
						if(p[offset12] < c_b)
						  if(p[offset13] < c_b)
							if(p[offset10] < c_b)
							  if(p[offset14] < c_b)
								if(p[offset15] < c_b)
								  if(p[offset1] < c_b)
									{}
								  else
									if(p[offset8] < c_b)
									  if(p[offset9] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								else
								  if(p[offset6] < c_b)
									if(p[offset7] < c_b)
									  if(p[offset8] < c_b)
										if(p[offset9] < c_b)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset5] < c_b)
								  if(p[offset6] < c_b)
									if(p[offset7] < c_b)
									  if(p[offset8] < c_b)
										if(p[offset9] < c_b)
										  {}
										else
										  continue;
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  if(p[offset1] < c_b)
								if(p[offset3] < c_b)
								  if(p[offset14] < c_b)
									if(p[offset15] < c_b)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
						  else
							continue;
						else
						  continue;
					  else
						continue;
				  else
					if(p[offset9] > cb)
					  if(p[offset7] > cb)
						if(p[offset8] > cb)
						  if(p[offset10] > cb)
							if(p[offset11] > cb)
							  if(p[offset6] > cb)
								if(p[offset5] > cb)
								  if(p[offset4] > cb)
									if(p[offset3] > cb)
									  {}
									else
									  if(p[offset12] > cb)
										{}
									  else
										continue;
								  else
									if(p[offset12] > cb)
									  if(p[offset13] > cb)
										{}
									  else
										continue;
									else
									  continue;
								else
								  if(p[offset12] > cb)
									if(p[offset13] > cb)
									  if(p[offset14] > cb)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset12] > cb)
								  if(p[offset13] > cb)
									if(p[offset14] > cb)
									  if(p[offset15] > cb)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  continue;
						  else
							continue;
						else
						  continue;
					  else
						continue;
					else if(p[offset9] < c_b)
					  if(p[offset10] < c_b)
						if(p[offset11] < c_b)
						  if(p[offset8] < c_b)
							if(p[offset12] < c_b)
							  if(p[offset13] < c_b)
								if(p[offset14] < c_b)
								  if(p[offset15] < c_b)
									{}
								  else
									if(p[offset6] < c_b)
									  if(p[offset7] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								else
								  if(p[offset5] < c_b)
									if(p[offset6] < c_b)
									  if(p[offset7] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset4] < c_b)
								  if(p[offset5] < c_b)
									if(p[offset6] < c_b)
									  if(p[offset7] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  if(p[offset3] < c_b)
								if(p[offset4] < c_b)
								  if(p[offset5] < c_b)
									if(p[offset6] < c_b)
									  if(p[offset7] < c_b)
										{}
									  else
										continue;
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
						  else
							if(p[offset1] < c_b)
							  if(p[offset12] < c_b)
								if(p[offset13] < c_b)
								  if(p[offset14] < c_b)
									if(p[offset15] < c_b)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						else
						  continue;
					  else
						continue;
					else
					  continue;
				else
				  if(p[offset7] > cb)
					if(p[offset8] > cb)
					  if(p[offset9] > cb)
						if(p[offset6] > cb)
						  if(p[offset5] > cb)
							if(p[offset4] > cb)
							  if(p[offset3] > cb)
								if(p[offset2] > cb)
								  if(p[offset1] > cb)
									{}
								  else
									if(p[offset10] > cb)
									  {}
									else
									  continue;
								else
								  if(p[offset10] > cb)
									if(p[offset11] > cb)
									  {}
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset10] > cb)
								  if(p[offset11] > cb)
									if(p[offset12] > cb)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  if(p[offset10] > cb)
								if(p[offset11] > cb)
								  if(p[offset12] > cb)
									if(p[offset13] > cb)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
						  else
							if(p[offset10] > cb)
							  if(p[offset11] > cb)
								if(p[offset12] > cb)
								  if(p[offset13] > cb)
									if(p[offset14] > cb)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						else
						  if(p[offset10] > cb)
							if(p[offset11] > cb)
							  if(p[offset12] > cb)
								if(p[offset13] > cb)
								  if(p[offset14] > cb)
									if(p[offset15] > cb)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						  else
							continue;
					  else
						continue;
					else
					  continue;
				  else if(p[offset7] < c_b)
					if(p[offset8] < c_b)
					  if(p[offset9] < c_b)
						if(p[offset6] < c_b)
						  if(p[offset5] < c_b)
							if(p[offset4] < c_b)
							  if(p[offset3] < c_b)
								if(p[offset2] < c_b)
								  if(p[offset1] < c_b)
									{}
								  else
									if(p[offset10] < c_b)
									  {}
									else
									  continue;
								else
								  if(p[offset10] < c_b)
									if(p[offset11] < c_b)
									  {}
									else
									  continue;
								  else
									continue;
							  else
								if(p[offset10] < c_b)
								  if(p[offset11] < c_b)
									if(p[offset12] < c_b)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							else
							  if(p[offset10] < c_b)
								if(p[offset11] < c_b)
								  if(p[offset12] < c_b)
									if(p[offset13] < c_b)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
						  else
							if(p[offset10] < c_b)
							  if(p[offset11] < c_b)
								if(p[offset12] < c_b)
								  if(p[offset13] < c_b)
									if(p[offset14] < c_b)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						else
						  if(p[offset10] < c_b)
							if(p[offset11] < c_b)
							  if(p[offset12] < c_b)
								if(p[offset13] < c_b)
								  if(p[offset14] < c_b)
									if(p[offset15] < c_b)
									  {}
									else
									  continue;
								  else
									continue;
								else
								  continue;
							  else
								continue;
							else
							  continue;
						  else
							continue;
					  else
						continue;
					else
					  continue;
				  else
					continue;
			}
			
			if(total == nExpectedCorners) 	
			{								
				if(nExpectedCorners==0)
				{
					nExpectedCorners=512;
					h = (xy*)realloc(h, sizeof(xy)*nExpectedCorners);
				}
				else
				{
					nExpectedCorners *=2;
					h = (xy*)realloc(h, sizeof(xy)*nExpectedCorners);
				}
			}
			h[total].x = x;
			h[total].y = y;
			total++;
				
	}
		
}
*ret_num_corners = total;
		return h;
}
void agast9_16_freeMemory()
{
	if(nExpectedCorners!=0)
	{
		free(h);
		nExpectedCorners=0;
	}
//	agast9_16_nms_freeMemory();
}
