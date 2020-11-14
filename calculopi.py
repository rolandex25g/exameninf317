# -*- coding: utf-8 -*-
"""
Created on Wed Nov 11 20:46:03 2020

@author: Rolando
"""

from multiprocessing import Process,Pool

def termino(n,posini,posfin,numpa):
    print("\n",n," posini:",posini," posfin:",posfin)
    paso=1/numpa
    suma=0.0
    for i in range(posini,posfin):
        x=(i+0.5)*paso
        suma=suma+4.0/(1.0+(x*x))
    return suma*paso
    
if __name__=='__main__':
    num_pasos=100000
    with Pool(4) as p:
        lista=p.starmap(termino,[(0,0,     25000,num_pasos),
                                 (1,25000, 50000,num_pasos),
                                 (2,50000, 75000,num_pasos),
                                 (3,75000,100000,num_pasos)])

    print(lista[:])
    pi=sum(lista)
    print("El valor de PI es "+str(pi))

