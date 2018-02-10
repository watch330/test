#define FirstRoom 1000
#define LastRoom 3099
#define sys_tip 14	//设置系统提示语句的颜色为 黄色
#define ERR 12		//设置错误提示语句的颜色为 红色
#define repeat 11	//设置重复用户输入信息的颜色为 蓝色
#define delay 500	//界面选项延迟出现时间(毫秒)
#define min_yyyy 2017

typedef struct Room
{
	int Number;
	int deposit;
	char *username;
	int Charge_mode;
	int Price_day, Price_hour;
	int yyyy, mm, dd, hh;
	int yyyyo, mmo, ddo, hho;
	int yyyyr, mmr, ddr, hhr;//签退日期 
	int sum;//实际消费金额 
	int day;//实际入住天数 
	int hour;//实际入住小时 
	int payment;//实际支付金额 
	int change;//找零 
	struct Room *next;
}Sroom;
typedef struct list
{
	Sroom *head;
	Sroom *tail;
}Slist;

void setPos(int x, int y);
void tab(int x, int y, char c);
void menu(Slist *pList);
void setColor(unsigned short ForeColor, unsigned short BackGroundColor);