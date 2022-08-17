import qrcode

img = qrcode.make('https://drive.google.com/file/d/1GEuyKHX7TSjQua_KFP6dT_FOdTwQjQXc/view')
type(img)  # qrcode.image.pil.PilImage
img.save("linkvideo.png")