from PIL import Image
poster=Image.open("bloom.png")
alpha=poster.split()[-1]
new=Image.new("RGBA",poster.size,(0,0,0,255))
new.paste(alpha, mask=alpha)
new.show()