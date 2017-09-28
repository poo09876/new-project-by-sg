typedef struct DataNode
{
    char* cmd;
    char* desc;
    int (*handler)();
    struct DataNode *next;
}tDataNode;

tDataNode* FindCommand(tDataNode *head, char *cmd);
int ShowAllCmd(tDataNode * head);
