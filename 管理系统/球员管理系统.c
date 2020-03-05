/*
 **********************************************
 *              ��Ա��Ϣ����ϵͳ              *
 **********************************************
 * ��    �ߣ��´���                           *
 * ѧ    У�������ʵ��ѧ                     *
 * ѧ    Ժ�������ѧԺ                       *
 * ר    ҵ�����ݿ�ѧ������ݼ���             *
 * ��    ����1902                             *
 * �������䣺1398635912@qq.com                *
 **********************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

struct User	{					                                            /* �ṹ�壬���ڴ洢�û���Ϣ */
    char username[20];                                                      /* �û��� */
    char password[40];                                                      /* ���� */
};

struct PlayerInformation {                                                  /* �ṹ�壬���ڴ洢��Ա��Ϣ */
    int num;                                                                /* ��Ա���� */
    char name[100];                                                         /* ��Ա���� */
    char nationality[50];                                                   /* ��Ա���� */
    char club[50];                                                          /* ��Ա���ھ��ֲ� */
    char position[20];                                                      /* ��Ա����λ�� */
    char remark[20];                                                        /* ��ע */
    struct PlayerInformation* next;                                         /* ָ����һ������ָ�� */
};

void safe_flush(FILE* fp);                                                  /* ������ջ����� */
struct PlayerInformation* CreateList(void);                                 /* ���ڴ���һ����� */
void mainMenu(void);                                                        /* ���ڴ������˵� */
int getMenuNum(void);                                                       /* ���ڻ�ȡ�˵�ѡ���� */
void CreateUsersFile(void);                                                 /* ���ڴ��������û��˺�������ļ� */
void Register(void);                                                        /* �����û�ע�� */
void Login(void);                                                           /* �����û���¼ */
void LoginMenu(void);                                                       /* ���ڴ�����¼���� */
struct PlayerInformation* CreatePlayer(void);                               /* ���ڴ����µ���Ա��Ϣ��� */
void AddPlayerByHead(struct PlayerInformation* list);                       /* ����������ͷ�������Ա��Ϣ */
void AddPlayerByEnd(struct PlayerInformation* list);                        /* �����������β�������Ա��Ϣ */
void AddPlayerByPos(struct PlayerInformation* list);                        /* ����������ָ��λ�ô������Ա��Ϣ */
void ShowAll(struct PlayerInformation* list);                               /* ������ʾ������Ա��Ϣ */
void DeletePlayerByNum(struct PlayerInformation* list, int num);            /* ���ڸ�����Ա����ɾ����Ա��Ϣ */
void DeletePlayerByName(struct PlayerInformation* list, char name[100]);    /* ���ڸ�����Ա����ɾ����Ա��Ϣ */
void FindPlayerByNum(struct PlayerInformation* list, int num);              /* ���ڸ�����Ա�����ѯ��Ա��Ϣ */
void FindPlayerByName(struct PlayerInformation* list, char name[100]);      /* ���ڸ�����Ա������ѯ��Ա��Ϣ */
void ChangePlayerByNum(struct PlayerInformation* list, int num);            /* ���ڸ�����Ա�����޸���Ա��Ϣ */
void ChangePlayerByName(struct PlayerInformation* list, char name[100]);    /* ���ڸ�����Ա�����޸���Ա��Ϣ */
void sorted(struct PlayerInformation* list);                                /* ���ڰ�����Ա����˳���������� */
void load(struct PlayerInformation* list);                                  /* ���ڶ�ȡ�ļ� */
void save(struct PlayerInformation* list);                                  /* ���ڱ����ļ� */
void Menu(struct PlayerInformation* list);                                  /* ���ڴ����˵� */

int main(void) {                                                            /* ������ */
    LoginMenu();
    return 0;
}

void safe_flush(FILE* fp) {                                                 /* ������ջ����� */
    int ch;
    while ((ch = fgetc(fp)) != EOF && ch != '\n');
}

struct PlayerInformation* CreateList(void) {                                /* ���ڴ���һ����� */
    struct PlayerInformation* list = (struct PlayerInformation*)malloc(sizeof(struct PlayerInformation));
    list->next = NULL;
    return list;
}

void mainMenu(void) {                                                       /* ���ڴ������˵� */
    printf("--------------------------------------------\n");
    printf("              ��Ա��Ϣ����ϵͳ\n");
    printf("--------------------------------------------\n");
    printf("1.�����Ա��Ϣ\n");
    printf("2.ɾ����Ա��Ϣ\n");
    printf("3.������Ա��Ϣ\n");
    printf("4.�޸���Ա��Ϣ\n");
    printf("5.����Ա��������\n");
    printf("6.��ʾ������Ա��Ϣ\n");
    printf("7.��ȡ�ļ��е�������Ա��Ϣ\n");
    printf("8.����Ա��Ϣ���浽�ļ�\n");
    printf("0.�˳���¼\n");
    printf("--------------------------------------------\n");
    printf("�������Ӧ�����֣�");
}

int getMenuNum(void) {                                                      /* ���ڻ�ȡ�˵�ѡ���� */
    mainMenu();
    int num;
    while (scanf("%d", &num) != 1 || num < 0 || num > 8) {
        safe_flush(stdin);
        system("cls");
        mainMenu();
        printf("\n����������������룺");
    }
    return num;
}

void CreateUsersFile(void) { 			                                    /* ���ڴ��������û��˺�������ļ� */
    FILE* fp;
    if ((fp = fopen("Users.txt", "rb")) == NULL) {
        if ((fp = fopen("Users.txt", "wb+")) == NULL) {
            printf("�޷������û��ļ��������˳�ϵͳ...\n");
            Sleep(3000);
            exit(0);
        }
    }
}

void Register(void)	{       			                                    /* �����û�ע�� */
    struct User a, b;
    FILE* fp;
    char temp[40];
    system("cls");
    printf("--------------------------------------------\n");
    printf("              ��Ա��Ϣ����ϵͳ\n");
    printf("--------------------------------------------\n");
    fp = fopen("Users.txt", "r");
    fread(&b, sizeof(struct User), 1, fp);			                        /* ����һ���ṹ���ַ��鵽b */
    printf("�������û�����");
    scanf("%s", &a.username);

    while (1) {
        if (strcmp(a.username, b.username))	{   	                        /* �Ƚ�����username�Ƿ���ͬ */
            if (!feof(fp))				                                    /* ���δ���ļ�β */
                fread(&b, sizeof(struct User), 1, fp);
            else
                break;
        }
        else {
            printf("\n���û����ѱ�ע������������ص�¼����...\n");
            fclose(fp);
            Sleep(3000);
            LoginMenu();
            return;
        }
    }

    printf("���������룺");
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
    printf("\n��ȷ�����룺");
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
            printf("\nע��ɹ����������ص�¼����...\n");
            fclose(fp);
            Sleep(3000);
            LoginMenu();
            return;
        }
        else {
            printf("\n�������벻ƥ�䣡���������룡\n");
            printf("���������룺");
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
            printf("\n��ȷ�����룺");
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

void Login(void) {       			                                        /* �����û���¼ */
    struct User a, b;
    FILE* fp;
    system("cls");
    printf("--------------------------------------------\n");
    printf("              ��Ա��Ϣ����ϵͳ\n");
    printf("--------------------------------------------\n");
    fp = fopen("Users.txt", "r");
    fread(&b, sizeof(struct User), 1, fp);			                        /* ����һ���ṹ���ַ��鵽b */
    printf("�������û�����");
    scanf("%s", &a.username);
    while (1) {
        if (strcmp(a.username, b.username) == 0)		                    /* ����д��û��� */
            break;
        else {
            if (!feof(fp))					                                /* ����ļ�û�ж��� */
                fread(&b, sizeof(struct User), 1, fp);
            else {
                printf("���û��������ڣ�\n");
                fclose(fp);
                system("pause");
                LoginMenu();
                return;
            }
        }
    }
    printf("���������룺");
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
        if (strcmp(a.password, b.password) == 0) {		                    /* �������ƥ�� */
            fclose(fp);
            printf("\n��¼�ɹ������ڽ�����Ա����ϵͳ...\n");
            Sleep(3000);
            struct PlayerInformation* list = CreateList();
            while (1)
                Menu(list);
            return;
        }
        else {
            printf("\n������󣡼������ص�¼����...\n");
            Sleep(3000);
            LoginMenu();
        }
    } while (strcmp(a.password, b.password) == 0);
}

void LoginMenu(void) {							                            /* ���ڴ�����¼���� */
    system("cls");
    printf("--------------------------------------------\n");
    printf("              ��Ա��Ϣ����ϵͳ\n");
    printf("--------------------------------------------\n");
    printf("1.��¼ϵͳ\n");
    printf("2.���û�ע��\n");
    printf("0.�˳�ϵͳ\n");
    printf("--------------------------------------------\n");
    printf("�������Ӧ�����֣�");
    int i;
    while (scanf("%d", &i) != 1 || i < 0 || i > 3) {
        safe_flush(stdin);
        printf("\n����������������룺");
    }
    switch (i) {
    case 1:
        Login();
        break;
    case 2:
        Register();
        break;
    case 0:
        printf("�ټ���\n");
        exit(0);
    }
}

struct PlayerInformation* CreatePlayer(void) {                              /* ���ڴ����µ���Ա��Ϣ��� */
    struct PlayerInformation* node = (struct PlayerInformation*)malloc(sizeof(struct PlayerInformation));
    node->next = NULL;
    if (!node) {
        printf("�����ڴ�ʧ��");
        return NULL;
    }
    printf("��������Ա���룺");
    while (scanf("%d", &node->num) != 1) {
        printf("\n����������������룺");
        safe_flush(stdin);
    }
    printf("��������Ա������");
    scanf("%s", node->name);
    printf("��������Ա������");
    scanf("%s", node->nationality);
    printf("��������Ա���ھ��ֲ���");
    scanf("%s", node->club);
    printf("��������Աλ�ã�");
    scanf("%s", node->position);
    printf("�����뱸ע��");
    scanf("%s", node->remark);
    return node;
}

void AddPlayerByHead(struct PlayerInformation* list) {                      /* ����������ͷ�������Ա��Ϣ */
    struct PlayerInformation* newPlayer = CreatePlayer();
    struct PlayerInformation* pos = list;
    while (pos->next != NULL) {
        if (pos->next->num == newPlayer->num) {
            printf("\n��Ա�����ظ���¼����Ϣʧ�ܣ�\n");
            return;
        }
        pos = pos->next;
    }
    newPlayer->next = list->next;
    list->next = newPlayer;
}

void AddPlayerByEnd(struct PlayerInformation* list) {                       /* �����������β�������Ա��Ϣ */
    struct PlayerInformation* newPlayer = CreatePlayer();
    struct PlayerInformation* pos = list;
    while (pos->next != NULL) {
        if (pos->next->num == newPlayer->num) {
            printf("\n��Ա�����ظ���¼����Ϣʧ�ܣ�\n");
            return;
        }
        pos = pos->next;
    }
    pos->next = newPlayer;
    newPlayer->next = NULL;
}

void AddPlayerByPos(struct PlayerInformation* list) {                       /* ����������ָ��λ�ô������Ա��Ϣ */
    struct PlayerInformation* pos = list;
    struct PlayerInformation* posF = list;
    if (pos->next == NULL) {
        printf("\n��Ա����Ϊ�գ����������Ա��Ϣ��\n");
        return;
    }
    struct PlayerInformation* newPlayer = CreatePlayer();
    while (pos->next != NULL) {
        if (pos->next->num == newPlayer->num) {
            printf("\n��Ա�����ظ���¼����Ϣʧ�ܣ�\n");
            return;
        }
        pos = pos->next;
    }
    int num;
    ShowAll(list);
    printf("��������Ա���룬��Ա��Ϣ��������ָ��λ��֮ǰ��");
    while (scanf("%d", &num) != 1) {
        printf("����������������룺");
        safe_flush(stdin);
    }
    struct PlayerInformation* pos1 = list->next;
    while (pos1->num != num) {
        pos1 = pos1->next;
        posF = posF->next;
        if (pos1 == NULL) {
            printf("δ�ҵ�ָ����Ա���룡\n");
            return;
        }
    }
    newPlayer->next = posF->next;
    posF->next = newPlayer;
}

void ShowAll(struct PlayerInformation* list) {                              /* ������ʾ������Ա��Ϣ */
    printf("\n");
    struct PlayerInformation* pos = list;
    printf("%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", "Number", "Name", "Nationality", "Club", "Position", "Remark");
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

void DeletePlayerByNum(struct PlayerInformation* list, int num) {           /* ���ڸ�����Ա����ɾ����Ա��Ϣ */
    struct PlayerInformation* posF = list;
    struct PlayerInformation* pos = posF->next;
    if (!posF->next) {
        printf("����Ϊ�գ�\n");
        return;
    }
    while (pos != NULL && pos->num != num) {
        pos = pos->next;
        posF = posF->next;
    }
    if (pos == NULL) {
        printf("����δ�ҵ���\n");
        return;
    }
    posF->next = pos->next;
    free(pos);
    return;
}

void DeletePlayerByName(struct PlayerInformation* list, char name[100]) {   /* ���ڸ�����Ա����ɾ����Ա��Ϣ */
    struct PlayerInformation* posF = list;
    struct PlayerInformation* pos = list->next;
    if (!posF->next) {
        printf("����Ϊ�գ�\n");
        return;
    }
    while (pos != NULL && *pos->name != *name) {
        pos = pos->next;
        posF = posF->next;
    }
    if (pos == NULL) {
        printf("����δ�ҵ���\n");
        return;
    }
    posF->next = pos->next;
    free(pos);
    return;
}

void FindPlayerByNum(struct PlayerInformation* list, int num) {             /* ���ڸ�����Ա�����ѯ��Ա��Ϣ */
    struct PlayerInformation* pos = list->next;
    if (!pos) {
        printf("����Ϊ�գ�\n");
        system("pause");
        return;
    }
    while (pos != NULL && pos->num != num)
        pos = pos->next;
    if (pos == NULL) {
        printf("����δ�ҵ���\n");
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

void FindPlayerByName(struct PlayerInformation* list, char name[100]) {     /* ���ڸ�����Ա������ѯ��Ա��Ϣ */
    struct PlayerInformation* pos = list->next;
    if (!pos) {
        printf("����Ϊ�գ�\n");
        system("pause");
        return;
    }
    while (pos != NULL && *pos->name != *name)
        pos = pos->next;
    if (pos == NULL) {
        printf("����δ�ҵ���\n");
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

void ChangePlayerByNum(struct PlayerInformation* list, int num) {           /* ���ڸ�����Ա�����޸���Ա��Ϣ */
    struct PlayerInformation* pos = list->next;
    if (!pos) {
        printf("����Ϊ�գ�\n");
        return;
    }
    while (pos != NULL && pos->num != num)
        pos = pos->next;
    if (pos == NULL) {
        printf("����δ�ҵ���\n");
        return;
    }
    printf("\n�������޸�֮�����Ա���룺");
    while (scanf("%d", &pos->num) != 1) {
        printf("\n����������������룺");
        safe_flush(stdin);
    }
    printf("�������޸�֮�����Ա������");
    scanf("%s", pos->name);
    printf("�������޸�֮�����Ա������");
    scanf("%s", pos->nationality);
    printf("�������޸�֮�����Ա���ֲ���");
    scanf("%s", pos->club);
    printf("�������޸�֮�����Աλ�ã�");
    scanf("%s", pos->position);
    printf("�������޸�֮��ı�ע��");
    scanf("%s", pos->remark);
}

void ChangePlayerByName(struct PlayerInformation* list, char name[100]) {   /* ���ڸ�����Ա�����޸���Ա��Ϣ */
    struct PlayerInformation* pos = list->next;
    if (!pos) {
        printf("����Ϊ�գ�\n");
        return;
    }
    while (pos != NULL && *pos->name != *name)
        pos = pos->next;
    if (pos == NULL) {
        printf("����δ�ҵ���\n");
        return;
    }
    printf("�������޸�֮�����Ա������");
    scanf("%s", pos->name);
    printf("�������޸�֮�����Ա������");
    scanf("%s", pos->nationality);
    printf("�������޸�֮�����Ա���ֲ���");
    scanf("%s", pos->club);
    printf("�������޸�֮�����Աλ�ã�");
    scanf("%s", pos->position);
    printf("�������޸�֮��ı�ע��");
    scanf("%s", pos->remark);
}

void sorted(struct PlayerInformation* list) {                               /* ���ڰ�����Ա����˳���������� */
    int numX;
    char nameX[100];
    char nationalityX[50];
    char clubX[50];
    char positionX[20];
    char remarkX[20];
    struct PlayerInformation* posF = list;
    struct PlayerInformation* pos = list->next;
    if (!posF->next) {
        printf("\n����Ϊ�գ��޷�����\n");
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

void load(struct PlayerInformation* list) {                                 /* ���ڶ�ȡ�ļ� */
    FILE* fp;
    if ((fp = fopen("Player.txt", "r")) == NULL) {
        printf("\n�ļ���ʧ�ܣ�\n");
        system("pause");
        return;
    }
    struct PlayerInformation* pos = CreateList();
    while ((fscanf(fp, "%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", &pos->num, pos->name, pos->nationality, pos->club, pos->position, pos->remark)) == 6) {
        list->next = pos;
        list = list->next;
        pos = CreateList();
    }
    printf("\n��Ϣ��ȡ�ɹ���\n");
    system("pause");
    return;
}

void save(struct PlayerInformation* list) {                                 /* ���ڱ����ļ� */
    FILE* fp;
    printf("�Ƿ����ԭ�ļ���(y/n)\n");
    printf("��������������ݣ�ϵͳ���Զ�������һ����");
    char i;
    safe_flush(stdin);
    while (scanf("%c", &i) != 1) {
        printf("����������������룺");
        safe_flush(stdin);
    }
    switch (i) {
    case 'y':
        if ((fp = fopen("Player.txt", "w")) == NULL) {
            printf("\n���ļ�ʧ�ܣ�\n");
            system("pause");
            return;
        }
        break;
    case 'n':
        if ((fp = fopen("Player.txt", "a")) == NULL) {
            printf("\n���ļ�ʧ�ܣ�\n");
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
    printf("\n��Ϣ����ɹ���\n");
    system("pause");
    return;
}

void Menu(struct PlayerInformation* list) {                                 /* ���ڴ����˵� */
    system("cls");
    int i;
    i = getMenuNum();
    switch (i) {
    case 1:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              ��Ա��Ϣ����ϵͳ\n");
        printf("--------------------------------------------\n");
        printf("1.�ڿ�ͷ��¼����Ա��Ϣ\n");
        printf("2.�ڽ�β��¼����Ա��Ϣ\n");
        printf("3.��ָ��λ��֮ǰ¼����Ա��Ϣ\n");
        printf("0.������һ��\n");
        printf("--------------------------------------------\n");
        printf("�������Ӧ�����֣�");
        int j;
        while (scanf("%d", &j) != 1 || j < 0 || j > 3) {
            safe_flush(stdin);
            printf("\n����������������룺");
        }
        switch (j) {
        case 1:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              ��Ա��Ϣ����ϵͳ\n");
            printf("--------------------------------------------\n");
            ShowAll(list);
            AddPlayerByHead(list);
            break;
        case 2:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              ��Ա��Ϣ����ϵͳ\n");
            printf("--------------------------------------------\n");
            ShowAll(list);
            AddPlayerByEnd(list);
            break;
        case 3:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              ��Ա��Ϣ����ϵͳ\n");
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
        printf("              ��Ա��Ϣ����ϵͳ\n");
        printf("--------------------------------------------\n");
        printf("1.������Ա����ɾ��\n");
        printf("2.������Ա����ɾ��\n");
        printf("0.������һ��\n");
        printf("--------------------------------------------\n");
        printf("�������Ӧ�����֣�");
        while (scanf("%d", &j) != 1 || j < 0 || j > 2) {
            safe_flush(stdin);
            printf("\n����������������룺");
        }
        switch (j) {
        case 1:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              ��Ա��Ϣ����ϵͳ\n");
            printf("--------------------------------------------\n");
            ShowAll(list);
            int num;
            printf("��������Ҫɾ������Ա�ĺ��룺");
            while (scanf("%d", &num) != 1) {
                printf("\n����������������룺");
                safe_flush(stdin);
            }
            DeletePlayerByNum(list, num);
            ShowAll(list);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              ��Ա��Ϣ����ϵͳ\n");
            printf("--------------------------------------------\n");
            ShowAll(list);
            char name[100];
            printf("��������Ҫɾ������Ա��������");
            while (scanf("%s", name) != 1) {
                printf("\n����������������룺");
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
        printf("              ��Ա��Ϣ����ϵͳ\n");
        printf("--------------------------------------------\n");
        printf("1.������Ա�����ѯ\n");
        printf("2.������Ա������ѯ\n");
        printf("0.������һ��\n");
        printf("--------------------------------------------\n");
        printf("�������Ӧ�����֣�");
        while (scanf("%d", &j) != 1 || j < 0 || j > 2) {
            safe_flush(stdin);
            printf("����������������룺");
        }
        switch (j) {
        case 1:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              ��Ա��Ϣ����ϵͳ\n");
            printf("--------------------------------------------\n");
            int num;
            printf("������Ҫ��ѯ����Ա�ĺ��룺");
            while (scanf("%d", &num) != 1) {
                printf("\n����������������룺");
                safe_flush(stdin);
            }
            FindPlayerByNum(list, num);
            break;
        case 2:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              ��Ա��Ϣ����ϵͳ\n");
            printf("--------------------------------------------\n");
            char name[100];
            printf("������Ҫ��ѯ����Ա��������");
            while (scanf("%s", name) != 1) {
                printf("\n����������������룺");
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
        printf("--------------------------------------------\n");
        printf("              ��Ա��Ϣ����ϵͳ\n");
        printf("--------------------------------------------\n");
        printf("1.������Ա�����޸�\n");
        printf("2.������Ա�����޸�\n");
        printf("0.������һ��\n");
        printf("--------------------------------------------\n");
        printf("�������Ӧ�����֣�\n");
        while (scanf("%d", &j) != 1 || j < 0 || j > 2) {
            safe_flush(stdin);
            printf("\n����������������룺");
        }
        switch (j) {
        case 1:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              ��Ա��Ϣ����ϵͳ\n");
            printf("--------------------------------------------\n");
            int num;
            printf("������Ҫ�޸ĵ���Ա�ĺ��룺");
            while (scanf("%d", &num) != 1) {
                printf("\n����������������룺");
                safe_flush(stdin);
            }
            ChangePlayerByNum(list, num);
            ShowAll(list);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              ��Ա��Ϣ����ϵͳ\n");
            printf("--------------------------------------------\n");
            char name[100];
            printf("������Ҫ�޸ĵ���Ա��������");
            while (scanf("%s", name) != 1) {
                printf("\n����������������룺");
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
        printf("              ��Ա��Ϣ����ϵͳ\n");
        printf("--------------------------------------------\n");
        sorted(list);
        ShowAll(list);
        system("pause");
        break;
    case 6:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              ��Ա��Ϣ����ϵͳ\n");
        printf("--------------------------------------------\n");
        ShowAll(list);
        system("pause");
        break;
    case 7:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              ��Ա��Ϣ����ϵͳ\n");
        printf("--------------------------------------------\n");
        load(list);
        break;
    case 8:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              ��Ա��Ϣ����ϵͳ\n");
        printf("--------------------------------------------\n");
        save(list);
        break;
    case 0:
        LoginMenu();
        break;
    }
}