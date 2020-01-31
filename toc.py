import tkinter
import tkinter.filedialog

count=0
toc=''
## 打开文件
filename_of_md=tkinter.filedialog.askopenfilename()
filename_of_toc=tkinter.filedialog.askopenfilename()

objecttoc=open(filename_of_toc,'w',encoding='utf-8')

for line in open(filename_of_md,'r',encoding='utf-8'):
    if line[0]!='#':
        continue
    else:
        for i in range(len(line)):
            if line[i]=='#':
                count+=1
        for k in range(2*(count-1)):
            toc+=' '
        if count%2!=0:
            toc+='-'
        if count%2==0:
            toc+='*'
        toc+='['
        toc+=line[count:len(line)]
        toc+='](#'
        toc+=line[count:len(line)]
        toc+=')\n'
objecttoc.write(toc)
objecttoc.close()