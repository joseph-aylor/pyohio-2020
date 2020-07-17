--title Pillow Basics
--date 2020-07-29
--author Joe Aylor
--center The basic usage of the Pillow Library
--newpage
--center What is pillow?


It is a user-friendly fork of an existing library called `PIL`

PIL stands for the Python Imaging Library

It is used to create and manipulate raster images.

A raster image is rectangles of pixel data

--newpage
--center Installation


Pillow can be installed through PyPi using Pip

Some of Pillow's optional features rely on external libraries

For basic stuff we will be using:
libjpeg for JPEG functionality.
zlib for compressed PNGs
libtiff for TIFF functionality
libfreetype provides type related services
libwebp provides the WebP format.
--newpage
--center Loading Images


There are a few simple ways to load images, from disk via a filename, via a BytesIO object, or from an open file.

To open from disk, you need to pass in a string to the open method.
This string is the path the pillow will use to open the image.

To open from bytes, pass in a BytesIO object from something like requests.

Once you are ready to save an image to disk call the save method.

Once you are done with an image, call the close method to remove it from memory.
--newpage
--center Converting Formats Formats

Converting between formats is as easy as using the correct file suffix.

Be careful that if you have transparency in the image, you are converting to a format that can handle the transparency.
You'll have to change the "mode" of the image.
--newpage
--center Resizing an Image

An image has a size property that's a tuple of two numbers.

There is a resize method on the Image object that allows you do define a new width and height.

There is also a thumbnail method that keeps the original proportions intact, but makes sure it fits in the dimensions given.
--newpage
--center Rotating Images

Rotating is done by the Image.rotate method.
It take the number of degrees you want the image rotated.


Transpose can do similar things, but only allows one of the following methods:
FLIP_LEFT_RIGHT
FLIP_TOP_BOTTOM
ROTATE_90
ROTATE_180
ROTATE_270
TRANSPOSE
TRANSVERSE
--newpage
--center Cropping Images

There is a crop method on the Image object.
It takes 4 points: left, upper, right, lower

The coordinate system of pillow starts with 0,0 being the top left
So, the bottom left pixel could be addressed by (0, image.height - 1)

--newpage
--center Copying and Pasting
You can paste one image into another.
If you have two image objects, you can call .paste on the "Background" image.

The paste method takes the image to be pasted along with either:
  a tuple representing the upper left corner of where you want the pasted image to begin
  a 4-tuple represnting the box you want the image pasted in (left, top, right, bottom)

If you want to retain transparencies of pasted images, you need to pass a mask for the third parameter.
You can also define a mask that's different than the pasted so that you can paste the image in a custom shape.

--newpage
--center Image Filters
There are several image filters built in to pillow.
You need to import ImageFilter from PIL

The built in filters are:

BLUR
CONTOUR
DETAIL
EDGE_ENHANCE
EDGE_ENHANCE_MORE
EMBOSS
FIND_EDGES
SHARPEN
SMOOTH
SMOOTH_MORE

There are also options to create your own filters.

--newpage
--center The End

Thanks for watching.
I hope you learned a bit about this useful library.

The slides and code can be found at https://github.com/joseph-aylor/pillowtalk

--newpage
--center Adding Text To Images




--newpage
--center Bands

Bands allow an image to be broken down by color.
There are also options to create your own filters.

Call the get_channel method to get 
Cover R G B and A
Look at get_channel method
Image.split()

--newpage
--center Image Modes
How an images pixels are handled by pillow relies
on the Image objects "Mode"

To view or change the mode of an image, use the mode property of the image object

There are many modes, but for basic things you need:
  RGB
    - The image has three "channels" red, blue and green
    - Each pixel value is 3X8 bits, representing a hex color RRGGBB.
      + So white would be 0xFFFFFF
  RGBA
    - The image has four "channels" red, blue, green, and transparency
  L
    - The image has one channel, so the image is black and white with no transparency.
    - Each pixel value is 8 bits

