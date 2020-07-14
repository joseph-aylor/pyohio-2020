Image.open('python.png')

response = requests.get('https://www.pyohio.org/2020/static/0d81f5680c11dff39a4c94c34269411a/a8246/pyohio-2020-square-transparent-400.png')
pyohio = Image.open(BytesIO(response.content))

#also tar


# ====resize# =====

logo.size

logo.resize((1400, 700)).save('long.png')
logo.resize((700, 1400)).save('tall.png')

logo.thumbnail((90, 700).save('tiny.png')

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