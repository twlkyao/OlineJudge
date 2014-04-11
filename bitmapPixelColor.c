/**
http://blog.csdn.net/twlkyao/article/details/23471741
*/
#include<stdio.h>

typedef struct { // The struct of color.
    int r;
    int g;
    int b;
}color;

typedef struct { // The struct of points.
    int x;
    int y;
}point;

typedef struct { // The struct of rectangle.
    point start;
    point end;
    color c;
}rec;

int main() {
    int n,m;
    int i,j;
    point pois[1000];
    rec recs[1000];
    while(scanf("%d %d", &n, &m) != EOF) {
        if(0 == n && 0 == m)
            return 0;
        for(i = 0; i < n; i++) { // Get the rectangles.
            scanf("%d %d %d %d %d %d %d", &recs[i].start.x, &recs[i].start.y, &recs[i].end.x, &recs[i].end.y, &recs[i].c.r, &recs[i].c.g, &recs[i].c.b);
        }
        
        for(j = 0; j < m; j++) { // Get the points.
            scanf("%d %d", &pois[j].x, &pois[j].y);
        }

        for(j = 0; j < m; j++) { // Check the points.
            for(i = n - 1; i >= 0; i--) {
 	        	if( pois[j].x >= recs[i].start.x && pois[j].x <= recs[i].end.x 
				 	&& pois[j].y >= recs[i].start.y && pois[j].y <= recs[i].end.y) { // In the rectangle.
		    		printf("%d %d %d\n", recs[i].c.r, recs[i].c.g, recs[i].c.b);
		    		break; // Get out of the loop.
				}
	    	}
	    	if(-1 == i) { // Not in any rectangle.
				printf("255 255 255\n");
	    	}
		}
   }    
   return 0;
}
