#include "Bitmap/bitmap.h"
#include <iostream>
#include <vector>

using namespace std;

//argc - number of arguments in command
//argv - each argument word, stored in an array
int main(int argc, char* argv[])
{
  Bitmap image;
  string filename;
  int row;
  int column;
  Pixel color;


  if (argc == 2)
  {
    filename = argv[1];
    image.open(filename);
    vector <vector <Pixel> > imagePixels;

    if(image.isImage() == true)
    {
      imagePixels = image.toPixelMatrix();
      cout<<"kendall.bmp is "<<imagePixels.size()<<" high and "<<imagePixels[0].size()<<" pixels wide\n";

      for(row = 0; row < imagePixels.size(); row++)
      {
        for(column = 0; column < imagePixels[0].size(); column++)
        {
          color = imagePixels[row][column];
          color.green = 0;
          color.blue = 0;

          imagePixels[row][column] = color;
        }
      }

    }
    else
    {
      cout<<"Image file must be a bitmap with 24-bit color depth.\n";
    }

    if(argc != 2)
    {
      cout<<"Please specify one image file!\n";
    }

    image.fromPixelMatrix( imagePixels);
    image.save("redness.bmp");

  }

  return 0;
}
