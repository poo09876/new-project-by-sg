
#include<stdio.h>
#include<stdlib.h>
#include"linktable.h"
int Help();
int Quit();
#define CMD_MAX_LEN    128
#define CMD_NUM        10
#define CMD_DESC       1024

typedef struct DataNode
{
    tLinkTableNode *pNext;
    char* cmd;
    char* desc;
    int (*handler)();
    struct DataNode *next;
}tDataNode;
tDataNode *FindCommand(tLinkTable *head, char *cmd)
{
    tDataNode* pNode=(tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
    if(!strcmp(pNode->cmd, cmd))
    {
        return pNode;
    }
    pNode=(tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    return NULL;
}
int ShowAllCmd(tLinkTable* head)
{
    tDataNode *pNode=(tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
    printf("%s - %s\n", pNode->cmd, pNode->desc);
    pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }       
    return 0;
}          
int InitMenuData(tLinkTable ** ppLinkTable)
{
    *ppLinkTable = CreateLinkTable();
    tDataNode* pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "help";
    pNode->desc = "this ia a help command:";
    pNode->handler = Help;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "version";
    pNode->desc = "menu program v1.1";
    pNode->handler = NULL;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "quit";
    pNode->desc = "quit from meau";
    pNode->handler = Quit;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    return 0;
}
tLinkTable* head = NULL;
int main()
{
    InitMenuData(&head);
    /*command line begin*/
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("please input a command >");
        scanf("%s", cmd);
        tDataNode *p = FindCommand(head, cmd);
        if(p == NULL)
        {
            printf("this is a wrong command");
	    continue;
        }
	printf("%s - %s\n", p->cmd, p->desc);
	if(p->handler != NULL)
	{
	    p->handler();
	}
    }
}
int Help()
{
    ShowAllCmd(head);
    return 0;
}
int Quit()
{
    exit(0);
}
