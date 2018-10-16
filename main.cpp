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
  if (argc == 2)
  {
    filename = argv[1];
    image.open(filename);
    if(image.isImage() == true)
    {
      vector <vector <Pixel> > imagePixels = image.toPixelMatrix();
      cout<<"kendall.bmp is "<<imagePixels.size()<<" high and "<<imagePixels[0].size()<<" pixels wide\n";
    }
    else
    {
     cout<<"Image file must be a bitmap with 24-bit color depth.\n";
    }
  }
  if(argc != 2)
  {
    cout<<"Please specify one image file!\n";
  }
   
  return 0;
}
