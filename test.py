#!/usr/bin/env python3


import subprocess
import sys


NULL = open("/dev/null", "w")

def say(m):
	sys.stdout.write(m)
	sys.stdout.flush()


def noter():
    note=0
    note1=0
    note2=0
    rc_base = subprocess.call("gcc -o palin_test palindrome.c palindrome_test.c",shell = True, stdout = NULL, stderr = NULL)

    if rc_base == 0:
        say("palindrome compilé\n")
    else:
        say("Echec de compilation palindrome\nNote provisoire : 0\n")
        sys.exit(1)
    process=subprocess.Popen("./palin_test 0",shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE, bufsize=0)
    (out,err)=process.communicate()
    say("Evaluation de la version force brute:")
    if(process.returncode==0):
        print(out.decode('utf-8'))
        note+=(int(err.decode('utf-8')))
        #print(err.decode('utf-8'))
    say("\tNote obtenue: "+ str(note)+"/50\n")
    
    process=subprocess.Popen("./palin_test 1",shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE, bufsize=0)
    (out,err)=process.communicate()
    say("Evaluation de la version programmation dynamique:")
    if(process.returncode==0):
        print(out.decode('utf-8'))
        note1+=(int(err.decode('utf-8')))
        #print(err.decode('utf-8'))
    say("\tNote obtenue: "+ str(note1)+"/50\n")        

    process=subprocess.Popen("./palin_test 2",shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE, bufsize=0)
    (out,err)=process.communicate()
    say("Evaluation de la version plateaux:")
    if(process.returncode==0):
        print(out.decode('utf-8'))
        note2+=(int(err.decode('utf-8')))
        #print(err.decode('utf-8'))
    say("\tNote obtenue: "+ str(note2)+ "/50\n")        
    print("\nNote provisoire : "+str(note+note1+note2)+"/150\n")
noter()
