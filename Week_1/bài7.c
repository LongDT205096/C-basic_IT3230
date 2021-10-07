/*main propotype*/

#include<stdio.h>
int main(int argc, char* argv[])
{
    double width, height;
    if(argc != 3) 
        {
            printf("Khong thoa man\n");
            return 1;
        }
        
        width = atof(argv[1]);
        height = atof(argv[2]);
        
        printf("Dien tich hinh chu nhat: %f\n", width * height);
        printf("Chu vi hinh chu nhat: %f\n",2 * (width + height));
        return 0;
}