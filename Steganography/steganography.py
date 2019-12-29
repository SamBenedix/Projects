#!/usr/bin/env python3

from utility import *

def steg_encode(msg, cover):
    coverindex = 0
    for char in msg:
        charbin = list(format(char, '0>8b'))
        for index in range(0,8):
            coverbin = cover[coverindex]
            if(charbin[index]=='0'):
                coverbin = coverbin & 0b11111110
            if(charbin[index]=='1'):
                coverbin = coverbin | 0b00000001
            cover[coverindex] = coverbin
            coverindex += 1

    return cover


def steg_decode(stego):
    decodedList = []
    finalWord = ''
    messagelength = int(len(stego)/8)
    stegoindex = 0
    for characters in range(0, messagelength):
        for num in range(0, 8):
            decodedList.append(bin(stego[stegoindex])[-1])
            stegoindex += 1
        if(int(''.join(decodedList), 2) == sentinel()):
            return finalWord

        finalWord += (chr(int(''.join(decodedList), 2)))
        decodedList = []

    return finalWord

def read_pgm(filename):
    data = []
    with open(filename, 'rb') as f:
        data = bytearray(f.read())
    return data


def write_pgm(filename,content):
    f = open(filename, 'wb')
    f.write(content)
    f.close()


def sentinel():
    return 0x80

def encode_pgm(msg, infile, outfile):
    content = read_pgm(infile)
    ri = raster_index(content)

    header = content[:ri]
    raster = content[ri:]
    encodedList = []
    encodedList = header

    encodedList.extend(steg_encode(msg, raster))

    write_pgm(outfile, encodedList)
    pass

def decode_pgm(infile):
    content = read_pgm(infile)
    ri = raster_index(content)

    header = content[:ri]
    raster = content[ri:]
    return steg_decode(raster)

if __name__ == '__main__':
    bytemessage = bytearray(b'Hello World')
    bytemessage.append(0x80)
    encode_pgm(bytemessage, 'plain.pgm', 'encoded.pgm')

    print(decode_pgm("encoded.pgm"))