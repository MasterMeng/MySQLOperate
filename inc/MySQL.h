#pragma once
#include "sql.h"

#include <mysql/mysql.h>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

class MySQL : public ISQL
{
public:
	//��ʼ��
	MySQL(string host, string user, string passwd, string db, unsigned port = 3306);

	//�������ݿ�
	bool connectDB();
	//�޸����ӵ����ݿ�
	bool changeDB(string dbname);
	//��ѯ�û����µ��������ݿ�
	void showDatabases();
	//��ѯ���ݿ����������ݱ�
	void showTables();
	//��ѯ���ݱ�ṹ
	void showTableStructure(string table);

	~MySQL();

public:
	//insert
	virtual bool Insert(string table, map<string, string> values);

	//delete
	virtual bool Delete(string table, map<string, string> values);

	//update
	virtual bool Update(string table, map<string, string> values);

	//select
	virtual bool Select(string table, map<string, string> values);

	//query
	virtual bool Query(string cmd);

private:
	void showDetails(MYSQL connect);

public:
	MYSQL connect;
	MYSQL_RES *res;
	MYSQL_ROW row;
	MYSQL_FIELD* fields;
	string sql;
	int ret;

private:
	string m_host;
	string m_user;
	string m_passwd;
	string m_dbname;
	int m_port;
};

string int2string(long num);
