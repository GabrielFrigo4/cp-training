import sys
import random
import base64
import hashlib

_0x1a2b3c = [0x46, 0x4c, 0x41, 0x47, 0x7b, 0x48, 0x41, 0x43, 0x4b, 0x45, 0x52, 0x4d, 0x41, 0x4e, 0x7d]
_0x9f8e7d = lambda x: x ^ 0xff
_0x5d4c3b = "abcdefghijklmnopqrstuvwxyz"
_0x7f6e5d = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
_0x888999 = "0123456789"

def _0xabc123():
    _temp = []
    for i in range(26):
        _temp.append(chr(ord('a') + i))
    return _temp

def _0xdef456(param1, param2=None):
    if param2 is None:
        param2 = random.randint(1, 100)
    return param1 * param2 % 256

def _0xbbb111(data):
    return [x for x in range(len(data)) if data[x] % 2 == 0]

def _0xccc222():
    _hash = hashlib.md5(b"d").hexdigest()
    return sum(ord(c) for c in _hash) % 100

def _0x111222():
    _d1 = _0xabc123()
    _d2 = [_0xdef456(i) for i in range(10)]
    _d3 = _0xccc222()
    
    _arr = []
    
    _operations = [
        lambda: 35 * 2,
        lambda: ord('K') + (lambda x: x)(1),
        lambda: int('41', 16),
        lambda: int(''.join(['1','0','0','0','1','1','1']), 2),
        lambda: 0x7b,
        lambda: (lambda g: ord(g) + 1)('G'),
        lambda: 97 - 0x20,
        lambda: ord('B') + (1 if True else 0),
        lambda: ord('J') + len("x"),
        lambda: ord('D') + int(str(1)),
        lambda: ord('Q') + (2 >> 1),
        lambda: ord('L') + (3 - 2),
        lambda: ord('Z') - (5 * 5),
        lambda: ord('M') + (1 & 1),
        lambda: 0x7d
    ]
    
    for _op in _operations:
        _val = _op()
        _arr.append(_val)
        if _val % 3 == 0:
            _d_calc = _0xdef456(_val)
    
    _final_d = _0xbbb111(_arr)
    return _arr

def _0x333444(_param):
    _result = ""
    _temp_storage = []
    
    for _idx, _num in enumerate(_param):
        _char = chr(_num)
        _result += _char
        _temp_storage.append(_char)
        
        if _idx % 2 == 0:
            _d = _0xdef456(_num, 42)
            _temp_hash = hashlib.sha256(str(_d).encode()).hexdigest()[:8]
    _counter = 0
    _multiplier = 13
    _modulo = 99
    
    for _c in _result:
        if _c in _0x7f6e5d:
            _counter += 1
        elif _c in _0x888999:
            _counter += 2
        else:
            _counter += 0
    
    _magic = (_counter * _multiplier) % _modulo
    
    _encoded_versions = {
        'b64': base64.b64encode(_result.encode()).decode(),
        'hex': _result.encode().hex(),
        'rev': _result[::-1],
        'ascii': [ord(c) for c in _result]
    }
    
    return _result, _magic

def _0x555666():
    _start_time = random.randint(1000, 9999)
    _secret = _0x111222()
    _output, _calc = _0x333444(_secret)
    
    print("Operação concluída com sucesso.")
    print(f"Resultado do processamento interno: {_calc}")
    
    _encoded = base64.b64encode(_output.encode()).decode()
    _reversed = _output[::-1]
    _hex_version = _output.encode().hex()
    _rot13 = _output.translate(str.maketrans(
        'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz',
        'NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm'
    ))
    
    _f_operations = [
        lambda x: x * 2,
        lambda x: x + 10,
        lambda x: x ^ 0xAA,
        lambda x: x // 3 if x > 0 else 0,
        lambda x: (x << 1) & 0xFF
    ]
    
    for _op in _f_operations:
        _d_result = _op(42)
        _temp = hashlib.md5(str(_d_result).encode()).hexdigest()

def _0xddd333():
    _f_data = [random.randint(65, 90) for _ in range(15)]
    _f_string = ''.join(chr(x) for x in _f_data)
    return _f_string

def _0xeee444():
    _patterns = ['FLAG{', '}', 'HACK', 'PASS', 'KEY']
    for p in _patterns:
        _temp = base64.b64encode(p.encode()).decode()

def _0x777888():
    _0xddd333()
    _0xeee444()
    _exec_string = base64.b64decode(b'XzB4NTU1NjY2KCk=').decode()
    exec(_exec_string)

if __name__ == "__main__":
    _0x777888()