import requests
url = "http://cs2107-ctfd-i.comp.nus.edu.sg:2782"
r = requests.delete(url)
print(r.text)