#pragma once
typedef int eletype;
struct dlist
{
	eletype val;
	struct dlist* prev;//��¼���ǽ���ǰһ��Ԫ��
	struct dlist* next;//��¼���ǽ��ĺ�һ��Ԫ��
};
typedef struct dlist* LinkNode;
typedef struct dlist Node;

//�˴�д���Ǵ�ͷ���
//��ʼ��ͷ���
LinkNode init();
//ִ�е��ǿ����ڴ溯��
LinkNode my_malloc(eletype data);
//ִ�е���ͷ�����
void pushfront(LinkNode header, eletype data);
//ִ�е���ͷɾ�Ĳ���
void popfront(LinkNode pheader);
//ִ�е���β�����
void pushback(LinkNode pheader, eletype data);
//ִ�е���βɾ�Ĳ���
void popback(LinkNode pheader);
//ִ�е�������Ԫ�ص�ɾ��
void delete_num(LinkNode pheader);
//ִ�е�������Ԫ�صĲ���
void insert_num(LinkNode pheader, eletype data);
//�������ЧԪ�ظ�����ͳ��
int cal_num(LinkNode pheader);
//����ĳһԪ���״γ��ֵĽ��
LinkNode search(LinkNode pheader,eletype data);
//˫��ѭ��������޸�
void rectify(LinkNode p, eletype olddata, eletype newdata);
//��������
void clean(LinkNode pheader);
//���������
void destory(LinkNode pheader);
//����Ĵ�ӡ
void print(LinkNode pheader);




