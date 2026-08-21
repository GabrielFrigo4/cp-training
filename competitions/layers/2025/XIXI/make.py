import os

def pbm(index):
	os.system(f'magick jpg/{index}.jpg -compress none pbm/{index}.pbm')

def ocr(index):
	os.system(f'ocrad --user-filter=filter.txt pbm/{index}.pbm > out/{index}.txt')

def proc(index):
	text = ''
	with open(f'out/{index}.txt', 'r') as file:
		text = file.read()
	text = text.replace(' ', '')
	text = text.replace('\n', '')
	with open(f'out/{index}.txt', 'w') as file:
		file.write(text)

def md5(index):
	os.system(f'md5sum out/{index}.txt')

def main():
	index_list = [4, 6, 7, 8, 9 ,60]
	for index in index_list:
		print(f'# INDEX {index} #')
		pbm(index)
		ocr(index)
		proc(index)
		md5(index)

main()