#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct User						// 结构体，用户信息 
{
	char username[20];
	char password[40];
};

struct PlayerInformation        // 结构体，球员信息
{
    int num;
    char name[100];
    char nationality[50];
    char club[50];
    char position[20];
    char remark[20];
    struct PlayerInformation *next;
};

void mainMenu();
struct PlayerInformation *CreateList();
void safe_flush(FILE *fp);
int getMenuNum();
void CreateUsersFile();
void Register();
void Login();
void LoginMenu();
struct PlayerInformation *CreatePlayer();
void AddPlayerByHead(struct PlayerInformation *list);
void AddPlayerByEnd(struct PlayerInformation *list);
void AddPlayerByPos(struct PlayerInformation *list);
void ShowAll(struct PlayerInformation *list);
void DeletePlayerByNum(struct PlayerInformation *list, int num);
void DeletePlayerByName(struct PlayerInformation *list, char name[100]);
void FindPlayerByNum(struct PlayerInformation *list, int num);
void FindPlayerByName(struct PlayerInformation *list, char name[100]);
void ChangePlayerByNum(struct PlayerInformation *list, int num);
void ChangePlayerByName(struct PlayerInformation *list, char name[100]);
void sorted(struct PlayerInformation *list);
void load(struct PlayerInformation *list);
void save(struct PlayerInformation *list);
void Menu(struct PlayerInformation *list);

int main(void)                  // 主函数
{
    LoginMenu();
    return 0;
}

void safe_flush(FILE *fp)           // 清除缓冲区函数
{
    int ch;
    while ((ch = fgetc(fp)) != EOF && ch != '\n');
}

struct PlayerInformation *CreateList()        // 创建一个结点
{
    struct PlayerInformation *list = (struct PlayerInformation *)malloc(sizeof(struct PlayerInformation));
    list->next = NULL;
    return list;
}

void mainMenu()                 // 主菜单函数
{
    printf("------------------------------------------\n");
    printf("              球员信息管理系统              \n");
    printf("------------------------------------------\n");
    printf("1.添加球员信息\n");
    printf("2.删除球员信息\n");
    printf("3.查找球员信息\n");
    printf("4.修改球员信息\n");
    printf("5.按球员号码排序\n");
    printf("6.显示所有球员信息\n");
    printf("7.读取文件中的所有球员信息\n");
    printf("8.将球员信息保存到文件\n");
    printf("0.退出登录\n");
    printf("------------------------------------------\n");
    printf("请输入对应的数字：");
}

int getMenuNum()              // 获得菜单选项编号，并且对错误输入进行处理
{
    mainMenu();
    int num;
    while (scanf("%d", &num) != 1 || num < 0 || num > 8)
    {
        safe_flush(stdin);
        system("cls");
        mainMenu();
        printf("\n输入错误！请重新输入：");
    }
    return num;
}

void CreateUsersFile()				// 创建储存用户账号密码的文件
{
	FILE *fp;
	if ((fp = fopen("Users.txt", "rb")) == NULL)
	{
		if ((fp = fopen("Users.txt", "wb+")) == NULL)
		{
			printf("无法建立用户文件！即将退出系统...\n");
			exit(0); 
		}
	}
}

void Register()							// 用户注册函数 
{
	struct User a, b;
	FILE *fp;
	a.password[40];
	char temp[40];
	system("cls");
    printf("------------------------------------------\n");
    printf("              球员信息管理系统              \n");
    printf("------------------------------------------\n");
    fp = fopen("Users.txt", "r");
    fread(&b, sizeof(struct User), 1, fp);			// 读入一个结构体字符块到b
	printf("请输入用户名：");
	scanf("%s", &a.username);
	
	while (1)
	{
		if (strcmp(a.username, b.username))			// 比较两个username是否相同，防止同一个用户名被注册多次 
		{
			if (!feof(fp))				// 如果未到文件尾
				fread(&b, sizeof(struct User), 1, fp);
			else
				break; 
		}
		else
		{
			printf("\n该用户名已被注册过！请重新注册！\n");
			fclose(fp);
			system("pause");
			Register();
			return;
		}
	}
	
	printf("请输入密码：");
	int i = 0;
	while ((a.password[i] = getch()) != '\r')
	{
		if (a.password[i] == '\b')
		{
			printf("\b \b");
			i--;
		}
		else
		{
			printf("*");
			i++;
		}
	}
	a.password[i] = '\0';
	
	printf("\n请确认密码：");
	i = 0;
	while ((temp[i] = getch()) != '\r')
	{
		if (temp[i] == '\b')
		{
			printf("\b \b");
			i--;
		}
		else
		{
			printf("*");
			i++;
		}
	}
	temp[i] = '\0';
	
	do
	{
		if (strcmp(a.password, temp) == 0)
		{
			fp = fopen("Users.txt", "a");
			fwrite(&a, sizeof(struct User), 1, fp);
			printf("\n注册成功！\n");
			fclose(fp);
			system("pause");
			LoginMenu();
			return;
		}
		else
		{
			printf("\n两次密码不匹配！请重新输入！\n");
			
			printf("请输入密码：");
			i = 0;
			while ((a.password[i] = getch()) != '\r')
			{
				if (a.password[i] == '\b')
				{
					printf("\b \b");
					i--;
				}
				else
				{
					printf("*");
					i++;
				}
			}
			a.password[i] = '\0';
			
			printf("\n请确认密码：");
			i = 0;
			while ((temp[i] = getch()) != '\r')
			{
				if (temp[i] == '\b')
				{
					printf("\b \b");
					i--;
				}
				else
				{
					printf("*");
					i++;
				}
			}
			temp[i] = '\0';
		}
	} while (1);
}

void Login()						// 用户登录函数
{
	struct User a, b;
	FILE *fp;
	system("cls");
    printf("------------------------------------------\n");
    printf("              球员信息管理系统              \n");
    printf("------------------------------------------\n");
	fp = fopen("Users.txt", "r");
	fread(&b, sizeof(struct User), 1, fp);			// 读入一个结构体字符块到b
	
	printf("请输入用户名：");
	scanf("%s", &a.username);
	while (1)
	{
		if (strcmp(a.username, b.username) == 0)		// 如果有此用户名
			break;
		else
		{
			if (!feof(fp))					// 如果文件没有读完
				fread(&b, sizeof(struct User), 1, fp);
			else
			{
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
	while ((a.password[i] = getch()) != '\r')
	{
		if (a.password[i] == '\b')
		{
			printf("\b \b");
			i--;
		}
		else
		{
			printf("*");
			i++;
		}
	}
	a.password[i] = '\0';
	do
	{
		if (strcmp(a.password, b.password) == 0)		// 如果密码匹配
		{
			fclose(fp);
			printf("\n登录成功！欢迎使用球员管理系统！\n");
			system("pause");
			struct PlayerInformation *list = CreateList();
		    while (1)
		        Menu(list);
			return;
		}
		else
		{
			printf("\n密码错误！请重新输入：");
			i = 0;
			while ((a.password[i] = getch()) != '\r')
			{
				if (a.password[i] == '\b')
				{
					printf("\b \b");
					i--;
				}
				else
				{
					printf("*");
					i++;
				}
			}
			a.password[i] = '\0';
		}
	} while (strcmp(a.password, b.password) == 0);
}

void LoginMenu()							// 登录界面
{
	system("cls");
    printf("------------------------------------------\n");
    printf("              球员信息管理系统              \n");
    printf("------------------------------------------\n");
    printf("1.登录系统\n");
    printf("2.新用户注册\n");
    printf("0.退出系统\n");
    printf("------------------------------------------\n");
    printf("请输入对应的数字：");
    int i;
    while (scanf("%d", &i) != 1 || i < 0 || i > 3)
    {
        safe_flush(stdin);
        printf("\n输入错误！请重新输入：");
    }
    switch (i)
    {
    	case 1:
    		Login();
    		break;
    	case 2:
    		Register();
    		break;
    	case 0:
    		printf("再见！\n"); 
    		exit(0);
	}
} 

struct PlayerInformation *CreatePlayer()         // 创建新的球员的结点
{
    struct PlayerInformation *node = (struct PlayerInformation *)malloc(sizeof(struct PlayerInformation));
    node->next = NULL;
    if (!node)
    {
        printf("申请内存失败");
        return NULL;
    }
    printf("请输入球员号码：");
    while (scanf("%d", &node->num) != 1)
    {
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

void AddPlayerByHead(struct PlayerInformation *list)         // 在链表中添加球员信息（头插法）
{
    struct PlayerInformation *newPlayer = CreatePlayer();
    struct PlayerInformation *pos = list;
    while (pos->next != NULL)
    {
        if (pos->next->num == newPlayer->num)
        {
            printf("\n球员号码重复，录入信息失败！\n");
            return;
        }
        pos = pos->next;
    }
    newPlayer->next = list->next;
    list->next = newPlayer;
}

void AddPlayerByEnd(struct PlayerInformation *list)          // 在链表中添加球员信息（尾插法）
{
    struct PlayerInformation *newPlayer = CreatePlayer();
    struct PlayerInformation *pos = list;
    while (pos->next != NULL)
    {
        if (pos->next->num == newPlayer->num)
        {
            printf("\n球员号码重复，录入信息失败！\n");
            return;
        }
        pos = pos->next;
    }
    pos->next = newPlayer;
    newPlayer->next = NULL;
}

void AddPlayerByPos(struct PlayerInformation *list)          // 在链表中添加球员信息（指定位置）
{
    struct PlayerInformation *pos = list;
    struct PlayerInformation *posF = list;
    if (pos->next == NULL)
    {
        printf("\n球员数据为空，不能添加球员信息！\n");
        return;
    }
    struct PlayerInformation *newPlayer = CreatePlayer();
    while (pos->next != NULL)
    {
        if (pos->next->num == newPlayer->num)
        {
            printf("\n球员号码重复，录入信息失败！\n");
            return;
        }
        pos = pos->next;
    }
    int num;
    ShowAll(list);
    printf("请输入球员号码，球员信息将插入在指定位置之前：");
    while (scanf("%d", &num) != 1)
    {
        printf("输入错误！请重新输入：");
        safe_flush(stdin);
    }
    struct PlayerInformation *pos1 = list->next;
    while (pos1->num != num)
    {
        pos1 = pos1->next;
        posF = posF->next;
        if (pos1 == NULL)
        {
            printf("未找到指定球员号码！\n");
            return;
        }
    }
    newPlayer->next = posF->next;
    posF->next = newPlayer;
}

void ShowAll(struct PlayerInformation *list)                // 打印所有球员信息
{
    printf("\n");
    struct PlayerInformation *pos = list;
    printf("%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", "Number", "Name", "Nationality", "Club", "Position", "Remark");
    while (pos->next)
    {
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

void DeletePlayerByNum(struct PlayerInformation *list, int num)    // 根据球员号码删除
{
    struct PlayerInformation *posF = list;
    struct PlayerInformation *pos = posF->next;
    if (!posF->next)
    {
        printf("数据为空！\n");
        return;
    }
    while (pos != NULL && pos->num != num)
    {
        pos = pos->next;
        posF = posF->next;
    }
    if (pos == NULL)
    {
        printf("数据未找到！\n");
        return;
    }
    posF->next = pos->next;
    free(pos);
    return;
}

void DeletePlayerByName(struct PlayerInformation *list, char name[100])    // 根据球员姓名删除
{
    struct PlayerInformation *posF = list;
    struct PlayerInformation *pos = list->next;
    if (!posF->next)
    {
        printf("数据为空！\n");
        return;
    }
    while (pos != NULL && *pos->name != *name)
    {
        pos = pos->next;
        posF = posF->next;
    }
    if (pos == NULL)
    {
        printf("数据未找到！\n");
        return;
    }
    posF->next = pos->next;
    free(pos);
    return;
}

void FindPlayerByNum(struct PlayerInformation *list, int num)       // 根据球员号码查阅信息
{
    struct PlayerInformation *pos = list->next;
    if (!pos)
    {
        printf("数据为空！\n");
        system("pause");
        return;
    }
    while (pos != NULL && pos->num != num)
        pos = pos->next;
    if (pos == NULL)
    {
        printf("数据未找到！\n");
        system("pause");
        return;
    }
    printf("%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", "Number", "Name", "Nationality", "Club", "Position", "Remark");
    printf("%d\t", pos->num);
    printf("%s\t\t", pos->name);
    printf("%s\t\t", pos->nationality);
    printf("%s\t\t", pos->club);
    printf("%s\t\t", pos->position);
    printf("%s\n\n", pos->remark);
    system("pause");
}

void FindPlayerByName(struct PlayerInformation *list, char name[100])       // 根据球员姓名查阅信息
{
    struct PlayerInformation *pos = list->next;
    if (!pos)
    {
        printf("数据为空！\n");
        system("pause");
        return;
    }
    while (pos != NULL && *pos->name != *name)
        pos = pos->next;
    if (pos == NULL)
    {
        printf("数据未找到！\n");
        system("pause");
        return;
    }
    printf("%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", "Number", "Name", "Nationality", "Club", "Position", "Remark");
    printf("%d\t", pos->num);
    printf("%s\t\t", pos->name);
    printf("%s\t\t", pos->nationality);
    printf("%s\t\t", pos->club);
    printf("%s\t\t", pos->position);
    printf("%s\n\n", pos->remark);
    system("pause");
}

void ChangePlayerByNum(struct PlayerInformation *list, int num)     // 根据球员号码修改信息
{
    struct PlayerInformation *pos = list->next;
    if (!pos)
    {
        printf("数据为空！\n");
        return;
    }
    while (pos != NULL && pos->num != num)
        pos = pos->next;
    if (pos == NULL)
    {
        printf("数据未找到！\n");
        return;
    }
    printf("\n请输入修改之后的球员号码：");
    while (scanf("%d", &pos->num) != 1)
    {
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

void ChangePlayerByName(struct PlayerInformation *list, char name[100])     // 根据球员姓名修改信息
{
    struct PlayerInformation *pos = list->next;
    if (!pos)
    {
        printf("数据为空！\n");
        return;
    }
    while (pos != NULL && *pos->name != *name)
        pos = pos->next;
    if (pos == NULL)
    {
        printf("数据未找到！\n");
        return;
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

void sorted(struct PlayerInformation *list)         // 按照球员号码升序排序
{
    int numX;
    char nameX[100];
    char nationalityX[50];
    char clubX[50];
    char positionX[20];
    char remarkX[20];
    struct PlayerInformation *posF = list;
    struct PlayerInformation *pos = list->next;
    if (!posF->next)
    {
        printf("\n数据为空，无法排序！\n");
        return;
    }
    while (pos->next)
    {
        posF = posF->next;
        pos = pos->next;
        if (posF->num > pos->num)
        {
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

void load(struct PlayerInformation *list)                   // 读取文件函数
{
    FILE *fp;
    if ((fp = fopen("Player.txt", "r")) == NULL)
    {
        printf("\n文件打开失败！\n");
        system("pause");
        return;
    }
    struct PlayerInformation *pos = CreateList();
    while ((fscanf(fp, "%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", &pos->num, pos->name, pos->nationality, pos->club, pos->position, pos->remark)) == 6)
    {
        list->next = pos;
        list = list->next;
        pos = CreateList();
    }
    printf("\n信息读取成功！\n");
    system("pause");
    return;
}

void save(struct PlayerInformation *list)                   // 保存文件函数
{
    FILE *fp;
    printf("是否清空原文件？(y/n)\n");
    printf("如果输入其他内容，系统将自动返回上一步：");
    char i;
    safe_flush(stdin);
    while (scanf("%c", &i) != 1)
    {
        printf("输入错误！请重新输入：");
        safe_flush(stdin);
    }
    switch (i)
    {
        case 'y':
            if ((fp = fopen("Player.txt", "w")) == NULL)
            {
                printf("\n打开文件失败！\n");
                system("pause");
                return;
            }
            break;
        case 'n':
            if ((fp = fopen("Player.txt", "a")) == NULL)
            {
                printf("\n打开文件失败！\n");
                system("pause");
                return;
            }
            break;
        default:
            return;
            break;
    }
    struct PlayerInformation *pos = list->next;
    while (pos)
    {
        fprintf(fp, "%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", pos->num, pos->name, pos->nationality, pos->club, pos->position, pos->remark);
        pos = pos->next;
    }
    fclose(fp);
    printf("\n信息保存成功！\n");
    system("pause");
    return;
}

void Menu(struct PlayerInformation *list)                   // 菜单函数
{
    system("cls");
    int i;
    i = getMenuNum();

    switch (i)
    {
        case 1:
            system("cls");
            printf("------------------------------------------\n");
            printf("              球员信息管理系统              \n");
            printf("------------------------------------------\n");
            printf("1.在开头处录入球员信息\n");
            printf("2.在结尾处录入球员信息\n");
            printf("3.在指定位置之前录入球员信息\n");
            printf("0.返回上一步\n");
            printf("------------------------------------------\n");
            printf("请输入对应的数字：");
            int j;
            while (scanf("%d", &j) != 1 || j < 0 || j > 3)
            {
                safe_flush(stdin);
                printf("\n输入错误！请重新输入：");
            }
            switch (j)
            {
                case 1:
                    system("cls");
                    printf("------------------------------------------\n");
                    printf("              球员信息管理系统              \n");
                    printf("------------------------------------------\n");
                    ShowAll(list);
                    AddPlayerByHead(list);
                    break;
                    
                case 2:
                    system("cls");
                    printf("------------------------------------------\n");
                    printf("              球员信息管理系统              \n");
                    printf("------------------------------------------\n");
                    ShowAll(list);
                    AddPlayerByEnd(list);
                    break;
                    
                case 3:
                    system("cls");
                    printf("------------------------------------------\n");
                    printf("              球员信息管理系统              \n");
                    printf("------------------------------------------\n");
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
            printf("------------------------------------------\n");
            printf("              球员信息管理系统              \n");
            printf("------------------------------------------\n");
            printf("1.根据球员号码删除\n");
            printf("2.根据球员姓名删除\n");
            printf("0.返回上一步\n");
            printf("------------------------------------------\n");
            printf("请输入对应的数字：");
            while (scanf("%d", &j) != 1 || j < 0 || j > 2)
            {
                safe_flush(stdin);
                printf("\n输入错误！请重新输入：");
            }
            switch (j)
            {
                case 1:
                    system("cls");
                    printf("------------------------------------------\n");
                    printf("              球员信息管理系统              \n");
                    printf("------------------------------------------\n");
                    ShowAll(list);
                    int num;
                    printf("请输入想要删除的球员的号码：");
                    while (scanf("%d", &num) != 1)
                    {
                        printf("\n输入错误！请重新输入：");
                        safe_flush(stdin);
                    }
                    DeletePlayerByNum(list, num);
                    ShowAll(list);
                    system("pause");
                    break;
                    
                case 2:
                    system("cls");
                    printf("------------------------------------------\n");
                    printf("              球员信息管理系统              \n");
                    printf("------------------------------------------\n");
                    ShowAll(list);
                    char name[100];
                    printf("请输入想要删除的球员的姓名：");
                    while (scanf("%s", name) != 1)
                    {
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
            printf("------------------------------------------\n");
            printf("              球员信息管理系统              \n");
            printf("------------------------------------------\n");
            printf("1.根据球员号码查询\n");
            printf("2.根据球员姓名查询\n");
            printf("0.返回上一步\n");
            printf("------------------------------------------\n");
            printf("请输入对应的数字：");
            while (scanf("%d", &j) != 1 || j < 0 || j > 2)
            {
                safe_flush(stdin);
                printf("输入错误！请重新输入：");
            }
            switch (j)
            {
                case 1:
                    system("cls");
                    printf("------------------------------------------\n");
                    printf("              球员信息管理系统              \n");
                    printf("------------------------------------------\n");
                    int num;
                    printf("请输入要查询的球员的号码：");
                    while (scanf("%d", &num) != 1)
                    {
                        printf("\n输入错误！请重新输入：");
                        safe_flush(stdin);
                    }
                    FindPlayerByNum(list, num);
                    break;
                    
                case 2:
                    system("cls");
                    printf("------------------------------------------\n");
                    printf("              球员信息管理系统              \n");
                    printf("------------------------------------------\n");
                    char name[100];
                    printf("请输入要查询的球员的姓名：");
                    while (scanf("%s", name) != 1)
                    {
                        printf("\n输入错误！请重新输入：");
                        safe_flush(stdin);
                    }
                    FindPlayerByName(list, name);
                    break;
                    
                case 0:
                    return;
                    break;
            }
            break;
            
        case 4:
            system("cls");
            printf("------------------------------------------\n");
            printf("              球员信息管理系统              \n");
            printf("------------------------------------------\n");
            printf("1.根据球员号码修改\n");
            printf("2.根据球员姓名修改\n");
            printf("0.返回上一步\n");
            printf("------------------------------------------\n");
            printf("请输入对应的数字：\n");
            while (scanf("%d", &j) != 1 || j < 0 || j > 2)
            {
                safe_flush(stdin);
                printf("\n输入错误，请重新输入：");
            }
            switch (j)
            {
                case 1:
                    system("cls");
                    printf("------------------------------------------\n");
                    printf("              球员信息管理系统              \n");
                    printf("------------------------------------------\n");
                    int num;
                    printf("请输入要修改的球员的号码：");
                    while (scanf("%d", &num) != 1)
                    {
                        printf("\n输入错误！请重新输入：");
                        safe_flush(stdin);
                    }
                    ChangePlayerByNum(list, num);
                    ShowAll(list);
                    system("pause");
                    break;
                    
                case 2:
                    system("cls");
                    printf("------------------------------------------\n");
                    printf("              球员信息管理系统              \n");
                    printf("------------------------------------------\n");
                    char name[100];
                    printf("请输入要修改的球员的姓名：");
                    while (scanf("%s", name) != 1)
                    {
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
            printf("------------------------------------------\n");
            printf("              球员信息管理系统              \n");
            printf("------------------------------------------\n");
            sorted(list);
            ShowAll(list);
    		system("pause");
            break;
            
        case 6:
            system("cls");
            printf("------------------------------------------\n");
            printf("              球员信息管理系统              \n");
            printf("------------------------------------------\n");
            ShowAll(list);
            system("pause");
            break;
            
        case 7:
            system("cls");
            printf("------------------------------------------\n");
            printf("              球员信息管理系统              \n");
            printf("------------------------------------------\n");
            load(list);
            break;
            
        case 8:
            system("cls");
            printf("------------------------------------------\n");
            printf("              球员信息管理系统              \n");
            printf("------------------------------------------\n");
            save(list);
            break;
            
        case 0:
            LoginMenu();
            break;
    }
}
