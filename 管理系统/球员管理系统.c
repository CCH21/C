/*
 **********************************************
 * 项目名称：球员信息管理系统                 *
 * 作    者：陈春晗                           *
 * 学    校：西安邮电大学                     *
 * 学    院：计算机学院                       *
 * 专    业：数据科学与大数据技术             *
 * 班    级：1902                             *
 * 学    号：04194041                         *
 * 电子邮箱：1398635912@qq.com                *
 **********************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

struct User {                                                                                 /* 结构体，用于存储用户信息 */
    char username[20];                                                                        /* 用户名 */
    char password[40];                                                                        /* 密码 */
};

struct PlayerInformation {                                                                    /* 结构体，用于存储球员信息 */
    int num;                                                                                  /* 球员号码 */
    char name[100];                                                                           /* 球员姓名 */
    char nationality[50];                                                                     /* 球员国籍 */
    char club[50];                                                                            /* 球员所在俱乐部 */
    char position[20];                                                                        /* 球员场上位置 */
    char remark[20];                                                                          /* 备注 */
    struct PlayerInformation* next;                                                           /* 指向下一个结点的指针 */
};

void safe_flush(FILE* fp);                                                                    /* 用于清空缓冲区 */
struct PlayerInformation* CreateList(void);                                                   /* 用于创建一个结点 */
void mainMenu(void);                                                                          /* 用于创建主菜单 */
int getMenuNum(void);                                                                         /* 用于获取菜单选项编号 */
void CreateUsersFile(void);                                                                   /* 用于创建储存用户账号密码的文件 */
void Register(void);                                                                          /* 用于用户注册 */
void Login(void);                                                                             /* 用于用户登录 */
void LoginMenu(void);                                                                         /* 用于创建登录界面 */
struct PlayerInformation* CreatePlayer(void);                                                 /* 用于创建新的球员信息结点 */
void AddPlayerByHead(struct PlayerInformation* list);                                         /* 用于在链表开头处添加球员信息 */
void AddPlayerByEnd(struct PlayerInformation* list);                                          /* 用于在链表结尾处添加球员信息 */
void AddPlayerByPos(struct PlayerInformation* list);                                          /* 用于在链表指定位置处添加球员信息 */
void ShowAll(struct PlayerInformation* list);                                                 /* 用于显示所有球员信息 */
void DeletePlayerByNum(struct PlayerInformation* list, int num);                              /* 用于根据球员号码删除球员信息 */
void DeletePlayerByName(struct PlayerInformation* list, char name[100]);                      /* 用于根据球员姓名删除球员信息 */
void FindPlayerByNum(struct PlayerInformation* list, int num);                                /* 用于根据球员号码查询球员信息 */
void FindPlayerByName(struct PlayerInformation* list, char name[100]);                        /* 用于根据球员姓名查询球员信息 */
void CombinedQuery(struct PlayerInformation* list, char position[20], char remark[20]);       /* 用于根据球员位置和状态组合查询球员信息 */
void ChangePlayerByNum(struct PlayerInformation* list, int num);                              /* 用于根据球员号码修改球员信息 */
void ChangePlayerByName(struct PlayerInformation* list, char name[100]);                      /* 用于根据球员号码修改球员信息 */
void sorted(struct PlayerInformation* list);                                                  /* 用于按照球员号码顺序升序排序 */
void sorted_reverse(struct PlayerInformation* list);                                          /* 用于按照球员号码顺序降序排序 */
void load(struct PlayerInformation* list);                                                    /* 用于读取文件 */
void save(struct PlayerInformation* list);                                                    /* 用于保存文件 */
void statistics_position(struct PlayerInformation* list);                                     /* 用于根据场上位置统计数据 */
void statistics_remark(struct PlayerInformation* list);                                       /* 用于根据备注统计数据 */
void com_statistics(struct PlayerInformation* list, char position[20], char remark[20]);      /* 用于根据球员位置和状态组合统计球员信息 */
void Menu(struct PlayerInformation* list);                                                    /* 用于创建菜单 */

int main(void) {                                                                              /* 主函数 */
    LoginMenu();
    return 0;
}

void safe_flush(FILE* fp) {                                                                   /* 用于清空缓冲区 */
    int ch;
    while ((ch = fgetc(fp)) != EOF && ch != '\n');
}

struct PlayerInformation* CreateList(void) {                                                  /* 用于创建一个结点 */
    struct PlayerInformation* list = (struct PlayerInformation*)malloc(sizeof(struct PlayerInformation));
    if (!list) {
        printf("申请内存失败\n");
        return NULL;
    }
    list->next = NULL;
    return list;
}

void mainMenu(void) {                                                                         /* 用于创建主菜单 */
    printf("--------------------------------------------\n");
    printf("              球员信息管理系统\n");
    printf("--------------------------------------------\n");
    printf("1.添加球员信息\n");
    printf("2.删除球员信息\n");
    printf("3.查找球员信息\n");
    printf("4.修改球员信息\n");
    printf("5.按球员号码排序\n");
    printf("6.显示所有球员信息\n");
    printf("7.读取文件中的所有球员信息\n");
    printf("8.将球员信息保存到文件\n");
    printf("9.统计数据\n");
    printf("0.退出登录\n");
    printf("--------------------------------------------\n");
    printf("请输入对应的数字：");
}

int getMenuNum(void) {                                                                        /* 用于获取菜单选项编号 */
    mainMenu();
    int num;
    while (scanf("%d", &num) != 1 || num < 0 || num > 9) {
        safe_flush(stdin);
        system("cls");
        mainMenu();
        printf("\n输入错误！请重新输入：");
    }
    return num;
}

void CreateUsersFile(void) {                                                                  /* 用于创建储存用户账号密码的文件 */
    FILE* fp;
    if ((fp = fopen("Users.txt", "rb")) == NULL) {
        if ((fp = fopen("Users.txt", "wb+")) == NULL) {
            printf("无法建立用户文件！即将退出系统...\n");
            Sleep(3000);
            exit(0);
        }
    }
}

void Register(void) {                                                                         /* 用于用户注册 */
    struct User a, b;
    FILE* fp;
    char temp[40];
    system("cls");
    printf("--------------------------------------------\n");
    printf("              球员信息管理系统\n");
    printf("--------------------------------------------\n");
    fp = fopen("Users.txt", "r");
    fread(&b, sizeof(struct User), 1, fp);                                                    /* 读入一个结构体字符块到b */
    printf("请输入用户名：");
    scanf("%s", &a.username);

    while (1) {
        if (strcmp(a.username, b.username)) {                                                 /* 比较两个username是否相同 */
            if (!feof(fp))                                                                    /* 如果未到文件尾 */
                fread(&b, sizeof(struct User), 1, fp);
            else
                break;
        }
        else {
            printf("\n该用户名已被注册过！即将返回登录界面...\n");
            fclose(fp);
            Sleep(3000);
            LoginMenu();
            return;
        }
    }

    printf("请输入密码：");
    int i = 0;
    while ((a.password[i] = _getch()) != '\r') {
        if (a.password[i] == '\b' && i >= 1) {
            printf("\b \b");
            i--;
        }
        else if (a.password[i] == '\b' && i == 0);
        else {
            printf("*");
            i++;
        }
    }
    a.password[i] = '\0';
    printf("\n请确认密码：");
    i = 0;
    while ((temp[i] = _getch()) != '\r') {
        if (temp[i] == '\b' && i >= 1) {
            printf("\b \b");
            i--;
        }
        else if (temp[i] == '\b' && i == 0);
        else {
            printf("*");
            i++;
        }
    }
    temp[i] = '\0';
    do {
        if (strcmp(a.password, temp) == 0) {
            fp = fopen("Users.txt", "a");
            fwrite(&a, sizeof(struct User), 1, fp);
            printf("\n注册成功！即将返回登录界面...\n");
            fclose(fp);
            Sleep(3000);
            LoginMenu();
            return;
        }
        else {
            printf("\n两次密码不匹配！请重新输入！\n");
            printf("请输入密码：");
            i = 0;
            while ((a.password[i] = _getch()) != '\r') {
                if (a.password[i] == '\b' && i >= 1) {
                    printf("\b \b");
                    i--;
                }
                else if (a.password[i] == '\b' && i == 0);
                else {
                    printf("*");
                    i++;
                }
            }
            a.password[i] = '\0';
            printf("\n请确认密码：");
            i = 0;
            while ((temp[i] = _getch()) != '\r') {
                if (temp[i] == '\b' && i >= 1) {
                    printf("\b \b");
                    i--;
                }
                else if (temp[i] == '\b' && i == 0);
                else {
                    printf("*");
                    i++;
                }
            }
            temp[i] = '\0';
        }
    } while (1);
}

void Login(void) {                                                                            /* 用于用户登录 */
    struct User a, b;
    FILE* fp;
    system("cls");
    printf("--------------------------------------------\n");
    printf("              球员信息管理系统\n");
    printf("--------------------------------------------\n");
    fp = fopen("Users.txt", "r");
    fread(&b, sizeof(struct User), 1, fp);                                                    /* 读入一个结构体字符块到b */
    printf("请输入用户名：");
    scanf("%s", &a.username);
    while (1) {
        if (strcmp(a.username, b.username) == 0)                                              /* 如果有此用户名 */
            break;
        else {
            if (!feof(fp))                                                                    /* 如果文件没有读完 */
                fread(&b, sizeof(struct User), 1, fp);
            else {
                printf("此用户名不存在！\n");
                fclose(fp);
                system("pause");
                LoginMenu();
                return;
            }
        }
    }
    printf("请输入密码：");
    int i = 0;
    while ((a.password[i] = _getch()) != '\r') {
        if (a.password[i] == '\b' && i >= 1) {
            printf("\b \b");
            i--;
        }
        else if (a.password[i] == '\b' && i == 0);
        else {
            printf("*");
            i++;
        }
    }
    a.password[i] = '\0';
    do {
        if (strcmp(a.password, b.password) == 0) {		                                          /* 如果密码匹配 */
            fclose(fp);
            printf("\n登录成功！正在进入球员管理系统...\n");
            Sleep(3000);
            struct PlayerInformation* list = CreateList();
            while (1)
                Menu(list);
            return;
        }
        else {
            printf("\n密码错误！即将返回登录界面...\n");
            Sleep(3000);
            LoginMenu();
        }
    } while (strcmp(a.password, b.password) == 0);
}

void LoginMenu(void) {                                                                        /* 用于创建登录界面 */
    system("cls");
    printf("--------------------------------------------\n");
    printf("              球员信息管理系统\n");
    printf("--------------------------------------------\n");
    printf("1.登录系统\n");
    printf("2.新用户注册\n");
    printf("3.关于\n");
    printf("0.退出系统\n");
    printf("--------------------------------------------\n");
    printf("请输入对应的数字：");
    int i;
    while (scanf("%d", &i) != 1 || i < 0 || i > 3) {
        safe_flush(stdin);
        printf("\n输入错误！请重新输入：");
    }
    switch (i) {
    case 1:
        Login();
        break;
    case 2:
        Register();
        break;
    case 3:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        printf("球员信息管理系统    [版本 v4.2.20200307]\n");
        printf("作者信息：陈春晗  西安邮电大学计算机学院\n");
        printf("          数据科学与大数据技术专业1902班\n");
        printf("电子邮箱：1398635912@qq.com\n");
        printf("--------------------------------------------\n");
        printf("版权声明：作者保留所有权利\n");
        printf("          禁止各种未经作者允许的复制行为\n");
        printf("--------------------------------------------\n");
        system("pause");
        LoginMenu();
        break;
    case 0:
        printf("正在退出，请稍候...\n");
        Sleep(3000);
        printf("再见！\n");
        exit(0);
    }
}

struct PlayerInformation* CreatePlayer(void) {                                                /* 用于创建新的球员信息结点 */
    struct PlayerInformation* node = (struct PlayerInformation*)malloc(sizeof(struct PlayerInformation));
    if (!node) {
        printf("申请内存失败\n");
        return NULL;
    }
    node->next = NULL;
    printf("请输入球员号码：");
    while (scanf("%d", &node->num) != 1) {
        printf("\n输入错误！请重新输入：");
        safe_flush(stdin);
    }
    printf("请输入球员姓名：");
    scanf("%s", node->name);
    printf("请输入球员国籍：");
    scanf("%s", node->nationality);
    printf("请输入球员所在俱乐部：");
    scanf("%s", node->club);
    printf("请输入球员位置：");
    scanf("%s", node->position);
    printf("请输入备注：");
    scanf("%s", node->remark);
    return node;
}

void AddPlayerByHead(struct PlayerInformation* list) {                                        /* 用于在链表开头处添加球员信息 */
    struct PlayerInformation* newPlayer = CreatePlayer();
    struct PlayerInformation* pos = list;
    while (pos->next != NULL) {
        if (pos->next->num == newPlayer->num) {
            printf("\n球员号码重复，录入信息失败！\n");
            return;
        }
        pos = pos->next;
    }
    newPlayer->next = list->next;
    list->next = newPlayer;
}

void AddPlayerByEnd(struct PlayerInformation* list) {                                         /* 用于在链表结尾处添加球员信息 */
    struct PlayerInformation* newPlayer = CreatePlayer();
    struct PlayerInformation* pos = list;
    while (pos->next != NULL) {
        if (pos->next->num == newPlayer->num) {
            printf("\n球员号码重复，录入信息失败！\n");
            return;
        }
        pos = pos->next;
    }
    pos->next = newPlayer;
    newPlayer->next = NULL;
}

void AddPlayerByPos(struct PlayerInformation* list) {                                         /* 用于在链表指定位置处添加球员信息 */
    struct PlayerInformation* pos = list;
    struct PlayerInformation* posF = list;
    if (pos->next == NULL) {
        printf("\n球员数据为空，不能添加球员信息！\n");
        return;
    }
    struct PlayerInformation* newPlayer = CreatePlayer();
    while (pos->next != NULL) {
        if (pos->next->num == newPlayer->num) {
            printf("\n球员号码重复，录入信息失败！\n");
            return;
        }
        pos = pos->next;
    }
    int num;
    ShowAll(list);
    printf("请输入球员号码，球员信息将插入在指定位置之前：");
    while (scanf("%d", &num) != 1) {
        printf("输入错误！请重新输入：");
        safe_flush(stdin);
    }
    struct PlayerInformation* pos1 = list->next;
    while (pos1->num != num) {
        pos1 = pos1->next;
        posF = posF->next;
        if (pos1 == NULL) {
            printf("未找到指定球员号码！\n");
            return;
        }
    }
    newPlayer->next = posF->next;
    posF->next = newPlayer;
}

void ShowAll(struct PlayerInformation* list) {                                                /* 用于显示所有球员信息 */
    printf("\n");
    struct PlayerInformation* pos = list;
    printf("%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", "Num.", "Name", "Nation.", "Club", "Pos.", "Remark");
    while (pos->next) {
        printf("%d\t", pos->next->num);
        printf("%s\t\t", pos->next->name);
        printf("%s\t\t", pos->next->nationality);
        printf("%s\t\t", pos->next->club);
        printf("%s\t\t", pos->next->position);
        printf("%s\n", pos->next->remark);
        pos = pos->next;
    }
    printf("\n");
}

void DeletePlayerByNum(struct PlayerInformation* list, int num) {                             /* 用于根据球员号码删除球员信息 */
    struct PlayerInformation* posF = list;
    struct PlayerInformation* pos = posF->next;
    if (!posF->next) {
        printf("数据为空！\n");
        return;
    }
    while (pos != NULL && pos->num != num) {
        pos = pos->next;
        posF = posF->next;
    }
    if (pos == NULL) {
        printf("数据未找到！\n");
        return;
    }
    posF->next = pos->next;
    free(pos);
    return;
}

void DeletePlayerByName(struct PlayerInformation* list, char name[100]) {                     /* 用于根据球员姓名删除球员信息 */
    struct PlayerInformation* posF = list;
    struct PlayerInformation* pos = list->next;
    if (!posF->next) {
        printf("数据为空！\n");
        return;
    }
    while (pos != NULL && *pos->name != *name) {
        pos = pos->next;
        posF = posF->next;
    }
    if (pos == NULL) {
        printf("数据未找到！\n");
        return;
    }
    posF->next = pos->next;
    free(pos);
    return;
}

void FindPlayerByNum(struct PlayerInformation* list, int num) {                               /* 用于根据球员号码查询球员信息 */
    printf("正在查找，请稍候...\n");
    Sleep(2000);
    struct PlayerInformation* pos = list->next;
    if (!pos) {
        printf("数据为空！\n");
        system("pause");
        return;
    }
    while (pos != NULL && pos->num != num)
        pos = pos->next;
    if (pos == NULL) {
        printf("数据未找到！\n");
        system("pause");
        return;
    }
    printf("%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", "Number", "Name", "Nation.", "Club", "Pos.", "Remark");
    printf("%d\t", pos->num);
    printf("%s\t\t", pos->name);
    printf("%s\t\t", pos->nationality);
    printf("%s\t\t", pos->club);
    printf("%s\t\t", pos->position);
    printf("%s\n\n", pos->remark);
    system("pause");
}

void FindPlayerByName(struct PlayerInformation* list, char name[100]) {                       /* 用于根据球员姓名查询球员信息 */
    printf("正在查找，请稍候...\n");
    Sleep(2000);
    struct PlayerInformation* pos = list->next;
    if (!pos) {
        printf("数据为空！\n");
        system("pause");
        return;
    }
    while (pos != NULL && *pos->name != *name)
        pos = pos->next;
    if (pos == NULL) {
        printf("数据未找到！\n");
        system("pause");
        return;
    }
    printf("%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", "Number", "Name", "Nation.", "Club", "Pos.", "Remark");
    printf("%d\t", pos->num);
    printf("%s\t\t", pos->name);
    printf("%s\t\t", pos->nationality);
    printf("%s\t\t", pos->club);
    printf("%s\t\t", pos->position);
    printf("%s\n\n", pos->remark);
    system("pause");
}

void CombinedQuery(struct PlayerInformation* list, char position[20], char remark[20]) {      /* 用于根据球员位置和状态组合查询球员信息 */
    printf("正在查找，请稍候...\n");
    Sleep(2000);
    int flag = 0;
    struct PlayerInformation* pos = list->next;
    if (!pos) {
        printf("数据为空！\n");
        system("pause");
        return;
    }
    printf("%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", "Number", "Name", "Nation.", "Club", "Pos.", "Remark");
    while (pos) {
        if (strcmp(pos->position, position) == 0) {
            if (strcmp(pos->remark, remark) == 0) {
                printf("%d\t", pos->num);
                printf("%s\t\t", pos->name);
                printf("%s\t\t", pos->nationality);
                printf("%s\t\t", pos->club);
                printf("%s\t\t", pos->position);
                printf("%s\n", pos->remark);
                flag = 1;
            }
        }
        pos = pos->next;
    }
    if (flag) {
        printf("\n信息查找成功！\n");
    }
    else {
        printf("\n未查找到相关信息！\n");
    }
    system("pause");
    return;
}

void ChangePlayerByNum(struct PlayerInformation* list, int num) {                             /* 用于根据球员号码修改球员信息 */
    struct PlayerInformation* pos = list->next;
    if (!pos) {
        printf("数据为空！\n");
        return;
    }
    while (pos != NULL && pos->num != num)
        pos = pos->next;
    if (pos == NULL) {
        printf("数据未找到！\n");
        return;
    }
    printf("\n请输入修改之后的球员号码：");
    while (scanf("%d", &pos->num) != 1) {
        printf("\n输入错误！请重新输入：");
        safe_flush(stdin);
    }
    printf("请输入修改之后的球员姓名：");
    scanf("%s", pos->name);
    printf("请输入修改之后的球员国籍：");
    scanf("%s", pos->nationality);
    printf("请输入修改之后的球员俱乐部：");
    scanf("%s", pos->club);
    printf("请输入修改之后的球员位置：");
    scanf("%s", pos->position);
    printf("请输入修改之后的备注：");
    scanf("%s", pos->remark);
}

void ChangePlayerByName(struct PlayerInformation* list, char name[100]) {                     /* 用于根据球员姓名修改球员信息 */
    struct PlayerInformation* pos = list->next;
    if (!pos) {
        printf("数据为空！\n");
        return;
    }
    while (pos != NULL && *pos->name != *name)
        pos = pos->next;
    if (pos == NULL) {
        printf("数据未找到！\n");
        return;
    }
    printf("\n请输入修改之后的球员号码：");
    while (scanf("%d", &pos->num) != 1) {
        printf("\n输入错误！请重新输入：");
        safe_flush(stdin);
    }
    printf("请输入修改之后的球员姓名：");
    scanf("%s", pos->name);
    printf("请输入修改之后的球员国籍：");
    scanf("%s", pos->nationality);
    printf("请输入修改之后的球员俱乐部：");
    scanf("%s", pos->club);
    printf("请输入修改之后的球员位置：");
    scanf("%s", pos->position);
    printf("请输入修改之后的备注：");
    scanf("%s", pos->remark);
}

void sorted(struct PlayerInformation* list) {                                                 /* 用于按照球员号码顺序升序排序 */
    int numX;
    char nameX[100];
    char nationalityX[50];
    char clubX[50];
    char positionX[20];
    char remarkX[20];
    struct PlayerInformation* posF = list;
    struct PlayerInformation* pos = list->next;
    if (!posF->next) {
        printf("\n数据为空，无法排序！\n");
        return;
    }
    while (pos->next) {
        posF = posF->next;
        pos = pos->next;
        if (posF->num > pos->num) {
            numX = posF->num;
            strcpy(nameX, posF->name);
            strcpy(nationalityX, posF->nationality);
            strcpy(clubX, posF->club);
            strcpy(positionX, posF->position);
            strcpy(remarkX, posF->remark);

            posF->num = pos->num;
            strcpy(posF->name, pos->name);
            strcpy(posF->nationality, pos->nationality);
            strcpy(posF->club, pos->club);
            strcpy(posF->position, pos->position);
            strcpy(posF->remark, pos->remark);

            pos->num = numX;
            strcpy(pos->name, nameX);
            strcpy(pos->nationality, nationalityX);
            strcpy(pos->club, clubX);
            strcpy(pos->position, positionX);
            strcpy(pos->remark, remarkX);

            sorted(list);
        }
    }
}

void sorted_reverse(struct PlayerInformation* list) {                                         /* 用于按照球员号码顺序降序排序 */
    int numX;
    char nameX[100];
    char nationalityX[50];
    char clubX[50];
    char positionX[20];
    char remarkX[20];
    struct PlayerInformation* posF = list;
    struct PlayerInformation* pos = list->next;
    if (!posF->next) {
        printf("\n数据为空，无法排序！\n");
        return;
    }
    while (pos->next) {
        posF = posF->next;
        pos = pos->next;
        if (posF->num < pos->num) {
            numX = posF->num;
            strcpy(nameX, posF->name);
            strcpy(nationalityX, posF->nationality);
            strcpy(clubX, posF->club);
            strcpy(positionX, posF->position);
            strcpy(remarkX, posF->remark);

            posF->num = pos->num;
            strcpy(posF->name, pos->name);
            strcpy(posF->nationality, pos->nationality);
            strcpy(posF->club, pos->club);
            strcpy(posF->position, pos->position);
            strcpy(posF->remark, pos->remark);

            pos->num = numX;
            strcpy(pos->name, nameX);
            strcpy(pos->nationality, nationalityX);
            strcpy(pos->club, clubX);
            strcpy(pos->position, positionX);
            strcpy(pos->remark, remarkX);

            sorted_reverse(list);
        }
    }
}

void load(struct PlayerInformation* list) {                                                   /* 用于读取文件 */
    FILE* fp;
    if ((fp = fopen("Player.txt", "r")) == NULL) {
        printf("\n文件打开失败！\n");
        system("pause");
        return;
    }
    struct PlayerInformation* pos = CreateList();
    while ((fscanf(fp, "%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", &pos->num, pos->name, pos->nationality, pos->club, pos->position, pos->remark)) == 6) {
        list->next = pos;
        list = list->next;
        pos = CreateList();
    }
    printf("正在读取信息，请稍候...\n");
    Sleep(2000);
    printf("信息读取成功！\n");
    system("pause");
    return;
}

void save(struct PlayerInformation* list) {                                                   /* 用于保存文件 */
    FILE* fp;
    printf("是否清空原文件？(y/n)\n");
    printf("如果输入其他内容，系统将自动返回上一步：");
    char i;
    safe_flush(stdin);
    while (scanf("%c", &i) != 1) {
        printf("输入错误！请重新输入：");
        safe_flush(stdin);
    }
    switch (i) {
    case 'y':
        if ((fp = fopen("Player.txt", "w")) == NULL) {
            printf("\n打开文件失败！\n");
            system("pause");
            return;
        }
        break;
    case 'n':
        if ((fp = fopen("Player.txt", "a")) == NULL) {
            printf("\n打开文件失败！\n");
            system("pause");
            return;
        }
        break;
    default:
        return;
        break;
    }
    struct PlayerInformation* pos = list->next;
    while (pos) {
        fprintf(fp, "%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", pos->num, pos->name, pos->nationality, pos->club, pos->position, pos->remark);
        pos = pos->next;
    }
    fclose(fp);
    printf("\n正在保存信息，请稍候...\n");
    Sleep(2000);
    printf("信息保存成功！\n");
    system("pause");
    return;
}

void statistics_position(struct PlayerInformation* list) {                                    /* 用于根据场上位置统计数据 */ 
    int cnt_players = 0;                                                                      /* 球员数量 */
    int cnt_GK = 0;                                                                           /* 位置：门将 */
    int cnt_DF = 0;                                                                           /* 位置：后卫 */
    int cnt_MF = 0;                                                                           /* 位置：中场 */
    int cnt_FW = 0;                                                                           /* 位置：前锋 */
    struct PlayerInformation* pos = list->next;
    while (pos) {
        cnt_players++;
        if (strcmp(pos->position, "GK") == 0) {
            cnt_GK++;
        }
        if (strcmp(pos->position, "DF") == 0) {
            cnt_DF++;
        }
        if (strcmp(pos->position, "MF") == 0) {
            cnt_MF++;
        }
        if (strcmp(pos->position, "FW") == 0) {
            cnt_FW++;
        }
        pos = pos->next;
    }
    system("cls");
    printf("--------------------------------------------\n");
    printf("              球员信息管理系统\n");
    printf("--------------------------------------------\n");
    printf("正在统计，请稍候...\n");
    Sleep(2000);
    printf("统计完成，正在生成报告...\n");
    Sleep(2000);
    printf("--------------------------------------------\n");
    printf("                  统计报告\n");
    printf("--------------------------------------------\n");
    printf("共有球员：%d人\n", cnt_players);
    printf("门将：%d人\n", cnt_GK);
    printf("后卫：%d人\n", cnt_DF);
    printf("中场：%d人\n", cnt_MF);
    printf("前锋：%d人\n", cnt_FW);
    printf("--------------------------------------------\n");
    system("pause");
    return;
}

void statistics_remark(struct PlayerInformation* list) {                                      /* 用于根据备注统计数据 */
    int cnt_players = 0;                                                                      /* 球员数量 */
    int cnt_normal = 0;                                                                       /* 状态：正常 */
    int cnt_injured = 0;                                                                      /* 状态：受伤 */
    int cnt_suspension = 0;                                                                   /* 状态：停赛 */
    int cnt_undetermined = 0;                                                                 /* 状态：待定 */
    struct PlayerInformation* pos = list->next;
    while (pos) {
        cnt_players++;
        if (strcmp(pos->remark, "normal") == 0) {
            cnt_normal++;
        }
        if (strcmp(pos->remark, "injured") == 0) {
            cnt_injured++;
        }
        if (strcmp(pos->remark, "suspension") == 0) {
            cnt_suspension++;
        }
        if (strcmp(pos->remark, "undetermined") == 0) {
            cnt_undetermined++;
        }
        pos = pos->next;
    }
    system("cls");
    printf("--------------------------------------------\n");
    printf("              球员信息管理系统\n");
    printf("--------------------------------------------\n");
    printf("正在统计，请稍候...\n");
    Sleep(2000);
    printf("统计完成，正在生成报告...\n");
    Sleep(2000);
    printf("--------------------------------------------\n");
    printf("                  统计报告\n");
    printf("--------------------------------------------\n");
    printf("共有球员：%d人\n", cnt_players);
    printf("正常：%d人\n", cnt_normal);
    printf("受伤：%d人\n", cnt_injured);
    printf("停赛：%d人\n", cnt_suspension);
    printf("待定：%d人\n", cnt_undetermined);
    printf("--------------------------------------------\n");
    system("pause");
    return;
}

void com_statistics(struct PlayerInformation* list, char position[20], char remark[20]) {     /* 用于根据球员位置和状态组合统计球员信息 */
    int cnt = 0;                                                                              /* 符合条件的球员数量 */
    struct PlayerInformation* pos = list->next;
    while (pos) {
        if (strcmp(pos->position, position) == 0) {
            if (strcmp(pos->remark, remark) == 0) {
                cnt++;
            }
        }
        pos = pos->next;
    }
    printf("正在统计，请稍候...\n");
    Sleep(2000);
    printf("统计完成，正在生成报告...\n");
    Sleep(2000);
    printf("--------------------------------------------\n");
    printf("                  统计报告\n");
    printf("--------------------------------------------\n");
    printf("符合要求的球员共有%d人\n", cnt);
    printf("请根据统计结果合理安排出战阵容\n");
    printf("预祝您比赛顺利！\n");
    printf("--------------------------------------------\n");
    system("pause");
    return;
}

void Menu(struct PlayerInformation* list) {                                                   /* 用于创建菜单 */
    system("cls");
    int i;
    i = getMenuNum();
    switch (i) {
    case 1:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        printf("1.在开头处录入球员信息\n");
        printf("2.在结尾处录入球员信息\n");
        printf("3.在指定位置之前录入球员信息\n");
        printf("0.返回上一步\n");
        printf("--------------------------------------------\n");
        printf("请输入对应的数字：");
        int j;
        while (scanf("%d", &j) != 1 || j < 0 || j > 3) {
            safe_flush(stdin);
            printf("\n输入错误！请重新输入：");
        }
        switch (j) {
        case 1:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            ShowAll(list);
            AddPlayerByHead(list);
            break;
        case 2:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            ShowAll(list);
            AddPlayerByEnd(list);
            break;
        case 3:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            ShowAll(list);
            AddPlayerByPos(list);
            break;
        case 0:
            return;
            break;
        }
        ShowAll(list);
        system("pause");
        break;
    case 2:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        printf("1.根据球员号码删除\n");
        printf("2.根据球员姓名删除\n");
        printf("0.返回上一步\n");
        printf("--------------------------------------------\n");
        printf("请输入对应的数字：");
        while (scanf("%d", &j) != 1 || j < 0 || j > 2) {
            safe_flush(stdin);
            printf("\n输入错误！请重新输入：");
        }
        switch (j) {
        case 1:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            ShowAll(list);
            int num;
            printf("请输入想要删除的球员的号码：");
            while (scanf("%d", &num) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            DeletePlayerByNum(list, num);
            ShowAll(list);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            ShowAll(list);
            char name[100];
            printf("请输入想要删除的球员的姓名：");
            while (scanf("%s", name) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            DeletePlayerByName(list, name);
            ShowAll(list);
            system("pause");
            break;
        case 0:
            return;
            break;
        }
        break;
    case 3:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        printf("1.根据球员号码查询\n");
        printf("2.根据球员姓名查询\n");
        printf("3.根据球员位置和状态组合查询\n");
        printf("0.返回上一步\n");
        printf("--------------------------------------------\n");
        printf("请输入对应的数字：");
        while (scanf("%d", &j) != 1 || j < 0 || j > 3) {
            safe_flush(stdin);
            printf("输入错误！请重新输入：");
        }
        switch (j) {
        case 1:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            int num;
            printf("请输入要查询的球员的号码：");
            while (scanf("%d", &num) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            FindPlayerByNum(list, num);
            break;
        case 2:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            char name[100];
            printf("请输入要查询的球员的姓名：");
            while (scanf("%s", name) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            FindPlayerByName(list, name);
            break;
        case 3:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            char position[20];
            char remark[20];
            printf("请输入要查询的球员的位置：");
            while (scanf("%s", position) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            printf("请输入要查询的球员的状态：");
            while (scanf("%s", remark) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            CombinedQuery(list, position, remark);
            break;
        case 0:
            return;
            break;
        }
        break;
    case 4:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        printf("1.根据球员号码修改\n");
        printf("2.根据球员姓名修改\n");
        printf("0.返回上一步\n");
        printf("--------------------------------------------\n");
        printf("请输入对应的数字：");
        while (scanf("%d", &j) != 1 || j < 0 || j > 2) {
            safe_flush(stdin);
            printf("\n输入错误，请重新输入：");
        }
        switch (j) {
        case 1:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            int num;
            printf("请输入要修改的球员的号码：");
            while (scanf("%d", &num) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            ChangePlayerByNum(list, num);
            ShowAll(list);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            char name[100];
            printf("请输入要修改的球员的姓名：");
            while (scanf("%s", name) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            ChangePlayerByName(list, name);
            ShowAll(list);
            system("pause");
            break;
        case 0:
            return;
            break;
        }
        break;
    case 5:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        printf("1.按球员号码升序排序\n");
        printf("2.按球员号码降序排序\n");
        printf("0.返回上一步\n");
        printf("--------------------------------------------\n");
        printf("请输入对应的数字：");
        while (scanf("%d", &j) != 1 || j < 0 || j > 2) {
            safe_flush(stdin);
            printf("\n输入错误，请重新输入：");
        }
        switch (j) {
        case 1:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            sorted(list);
            ShowAll(list);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            sorted_reverse(list);
            ShowAll(list);
            system("pause");
            break;
        case 0:
            return;
            break;
        }
        break;
    case 6:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        ShowAll(list);
        system("pause");
        break;
    case 7:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        load(list);
        break;
    case 8:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        save(list);
        break;
    case 9:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        printf("1.按球员位置统计数据\n");
        printf("2.按球员状态统计数据\n");
        printf("3.组合统计数据\n");
        printf("0.返回上一步\n");
        printf("--------------------------------------------\n");
        printf("请输入对应的数字：");
        while (scanf("%d", &j) != 1 || j < 0 || j > 3) {
            safe_flush(stdin);
            printf("\n输入错误，请重新输入：");
        }
        switch (j) {
        case 1:
            statistics_position(list);
            break;
        case 2:
            statistics_remark(list);
            break;
        case 3:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            char position[20];
            char remark[20];
            printf("请输入要统计的球员位置：");
            while (scanf("%s", position) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            printf("请输入要统计的球员状态：");
            while (scanf("%s", remark) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            com_statistics(list, position, remark);
            break;
        case 0:
            return;
            break;
        }
        break;
    case 0:
        printf("正在退出，请稍候...\n");
        Sleep(3000);
        LoginMenu();
        break;
    }
}