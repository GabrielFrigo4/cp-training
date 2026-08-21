import hashlib
import string

alfabeto = list(string.ascii_letters + string.digits)
per = [0, 0]
pos = [33, 40]
site = 'https://forms.layers.education/xL*tB4sE0*zVp7KfG2QhU?answ=f8574a9'
hash_key = 'a90cdb5f8b48d02e6026af077aed0eb1'

def permutate_list(my_list, size):
    for i in range(len(my_list)):
        my_list[i] += 1
        if my_list[i] == size and i < len(my_list) - 1:
            my_list[i] = 0
        else:
            break
    return my_list

def compute_hash(my_string):
    m = hashlib.md5()
    m.update(my_string.encode('utf-8'))
    return m.hexdigest()

while (per[-1] < len(alfabeto)):
    per = permutate_list(per, len(alfabeto))
    if (per[-1] == len(alfabeto)):
        break
    list_site = list(site)
    for i in range (len(pos)):
        list_site[pos[i]] = alfabeto[per[i]]
    tmp_site = ''.join(list_site)
    if (compute_hash(tmp_site) == hash_key):
        print(tmp_site)
