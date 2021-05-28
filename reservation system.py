


# ԤԼϵͳ������
def index():
    print("======欢迎使用预约系统======")
    print("1.新增实验室预约")
    print("2.显示目前全部预约情况")
    print("3.查询预约情况")
    print("4.修改预约情况")
    print("5.退出\n")


# ����ʵ���ҿ��б�
info = []


# ����ʵ����ԤԼ
def input_info():
    stuId = input("请输入你的学号\n")
    stuName = input("请输入你的姓名\n")
    time = input("请输入你需要预约的时间\n")
    room = input("请输入你需要预约的实验室\n")
    global info
    for k in info:
        if stuId == k["stuId"]:
            print("你已经预约过了\n")
            return
    info_dict = dict()
    info_dict["stuId"] = stuId
    info_dict["stuName"] = stuName
    info_dict["time"] = time
    info_dict["room"] = room
    info.append(info_dict)


# ��ʾĿǰȫ����ԤԼ��Ϣ
def show_info():
    print("全部的预约信息如下\n")
    for k in info:
        print(f'学号{k["stuId"]}\t名字{k["stuName"]}\t预约时间{k["time"]}\t实验室{k["room"]}\n')


# ��ѯԤԼ��ￄ1�7
def select_info():
    select = input("请输入你的学号\n")
    for k in info:
        if select == k["stuId"]:
            print(f'你好{k["stuName"]},你预约的时间是{k["time"]},实验室是{k["room"]}\n')
            break
    else:
        print("找不到预约的信息\n")


# �޸�ԤԼ��Ϣ
def modify_info():
    modify = input("请输入你的学号\n")
    for k in info:
        if modify == k["stuId"]:
            print(f'你好{k["stuName"]}')
            time = input("请输入你所需要预约的时间\n")
            room = input("请输入你所需要预约的实验室\n")
            k["time"] = time
            k["room"] = room
            break
    else:
        print("找不到预约情况\n")


# ������
while 'true':
    index()
    i = input("请输入你需要使用的功能对应的序号\n")
    if i == "1":
        input_info()
    elif i == "2":
        show_info()
    elif i == "3":
        select_info()
    elif i == "4":
        modify_info()
    elif i == "5":
        flag = input("是否退出系统 yes or no\n")
        if flag == "yes":
            break
    else:
        print("输入有误,请重新输入\n")
