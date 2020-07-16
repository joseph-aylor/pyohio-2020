import requests

from PIL import Image, ImageFilter
from io import BytesIO

logo = Image.open('python.png')

response = requests.get('https://www.pyohio.org/2020/static/0d81f5680c11dff39a4c94c34269411a/a8246/pyohio-2020-square-transparent-400.png')
pyohio = Image.open(BytesIO(response.content))

# also tar

# ====resize# =====

logo.size

logo.resize((1400, 700)).save('long.png')
logo.resize((700, 1400)).save('tall.png')

logo.thumbnail((90, 700)).save('tiny.png')

logo = Image.open('python.png')

logo.resize((10000, 10000), Image.ANTIALIAS)

# ====rotating images# ====
logo.rotate(45).save('tilted.png')
logo.rotate(180).save('flipped.png')

pyohio.transpose(method=Image.TRANSVERSE).save('tv.png')
pyohio.transpose(method=Image.TRANSPOSE).save('tv.png')
pyohio.transpose(method=Image.FLIP_LEFT_RIGHT).save('tv.png')
pyohio.transpose(method=Image.ROTATE_270).save('tv.png')


# ====cropping images# =====
logo.crop((350, 350, 699, 696)).save('chopped.tiff')
logo.crop((0, 350, 699, 696)).save('chopped.tiff')

# ====copy and pasting# ====

cincinnati = Image.open('cincinnati.png')
cincinnati.paste(logo)
cincinnati.save('cincinnati_logo.png')
center_image_x = int((cincinnati.width - logo.width)/2)
center_image_y = int((cincinnati.height - logo.height)/2)
cincinnati = Image.open('cincinnati.png')
cincinnati.paste(logo, (center_image_x, center_image_y))
cincinnati.save('cincinnati_logo.png')
cincinnati = Image.open('cincinnati.png')
cincinnati.paste(logo, (center_image_x, center_image_y), mask=logo)

# ====filters# ====
cincinnati.filter(ImageFilter.BLUR).show()
cincinnati.filter(ImageFilter.CONTOUR).show()
cincinnati.filter(ImageFilter.EDGE_ENHANCE_MORE).show()
cincinnati.filter(ImageFilter.EMBOSS).show()
cincinnati.filter(ImageFilter.FIND_EDGES).show()
cincinnati.filter(ImageFilter.SHARPEN).show()
cincinnati.filter(ImageFilter.SMOOTH_MORE).show()
