/*โปรแกรมกู้คืนรูปภาพจากไฟล์ที่กำหนดมาให้*/

#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>

typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    if(argc !=2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    FILE *file = fopen( argv[1], "r");
    if(!file)
    {
        return 0;
    }

    BYTE buffer[512];
    char output[8] = " ";
    int count=0;
    while (1)
    {
        fread(&buffer, sizeof(BYTE) * 512, 1, file);
        NEWFILE:
        if (feof(file))
        {
            break;
        }
        else if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] < 0xf0))//found JPEG header
        {
            if (count > 9)
            {
                sprintf(output, "0%d.jpg", count);
            }
            else
            {
                sprintf(output, "00%d.jpg", count);
            }
            count++;
        }
            FILE *jpeg = fopen(output, "w");
            while (1)
            {
                fwrite(&buffer, sizeof(BYTE) * 512, 1, jpeg);
                fread(&buffer, sizeof(BYTE) * 512, 1, file);
                if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] < 0xf0)) || feof(file))//new JPEG header or EOF
                {
                    fclose(jpeg);
                    goto NEWFILE;
                    //break;
                }
            }
    }

}
