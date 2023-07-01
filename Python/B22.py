# Toms Madžuls, tm22005
# B22. Sastādīt programmu, kura reizina un dala racionālus skaitļus, racionālos skaitļus uzdodot kā divu veselu skaitļu pāri 
# (1/3 tiek uzdota kā divi skaitļi 1 un 3). Rezultātam jābūt kā nesaīsināmam daļskaitlim. Risinājumā izmantot funkciju, 
# kas reizina divus racionālus skaitļus un funkciju, kas pārveido racionālu skaitli par nesaīsināmu daļskaitli.
# Programma izveidota: 12.10.2022
import math
izvele = ''

def saisinasana(a, b):
    rezultats = a/math.gcd(a, b) #pirmais arguments izsaucot funkciju tiks atgriezts kā saisinata vertiba
    return rezultats

def dalisana(lu, ld, ru, rd,):
    dal1 = (lu * rd)            #dalisana, reizinot racionalos skaitlus krusteniski
    dal2 = (ld * ru)
    print("Dalijums: ", int(saisinasana(dal1, dal2)) ,"/", int(saisinasana(dal2, dal1))) #iegutos rezultatus dala ar kopigo lielako dalitaju izmantojot saisinasanas funkciju

def reizinasana(lu, ld, ru, rd,):
    reiz1 = (lu * ru)           #sareizina racionalos skaitlus
    reiz2 = (ld * rd)
    print("Reizinajums: ", int(saisinasana(reiz1, reiz2)) ,"/", int(saisinasana(reiz2, reiz1)))

while True:  #kamer izvele bus patiesa, tikmer programma turpinas izpildi
    izvele = input('Vai turpinat? y/n: ')
    if izvele.lower() == 'y':  #izvele bija 'yes'
        lu, ld = input("Ievadiet 1. racionalo skaitli (m / n): ").split() #iegust racionalo skaitli ka string un tad sadala 2 atseviskos sk.
        ru, rd = input("Ievadiet 2. racionalo skaitli (m / n): ").split()
        lu = int(lu)                                                      #parvers string par int
        ld = int(ld)
        ru = int(ru)
        rd = int(rd)
        if (ld <= 0): #1. dalitajs nav naturals sk.
            print("1. Dalitajam jabut naturalam skaitlim!")
        elif (rd <= 0): #2. dalitajs nav naturals sk.
            print("2. Dalitajam jabut naturalam skaitlim!")
        else:
            reizinasana(lu, ld, ru, rd)
            dalisana(lu, ld, ru, rd)
    elif izvele.lower() == 'n': #izvele bija 'no', beidz programmas darbibu
        break
    else: #netika ievadits y/n
        print('Ierakstiet y/n')