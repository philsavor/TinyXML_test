#include <iostream>
#include <string>

#include "tinyxml.h"
#include "tinystr.h"

using namespace std;

bool CreateXmlFile(string& szFileName)
{//����xml�ļ�,szFilePathΪ�ļ������·��,�������ɹ�����true,����false
    try
    {
        //����һ��XML���ĵ�����
        TiXmlDocument *myDocument = new TiXmlDocument();
        //����һ����Ԫ�ز����ӡ�
        TiXmlElement *RootElement = new TiXmlElement("Persons");
        myDocument->LinkEndChild(RootElement);
        //����һ��PersonԪ�ز����ӡ�
        TiXmlElement *PersonElement = new TiXmlElement("Person");
        RootElement->LinkEndChild(PersonElement);
        //����PersonԪ�ص����ԡ�
        PersonElement->SetAttribute("ID", "1");
        //����nameԪ�ء�ageԪ�ز����ӡ�
        TiXmlElement *NameElement = new TiXmlElement("name");
        TiXmlElement *AgeElement = new TiXmlElement("age");
        PersonElement->LinkEndChild(NameElement);
        PersonElement->LinkEndChild(AgeElement);
        //����nameԪ�غ�ageԪ�ص����ݲ����ӡ�
        TiXmlText *NameContent = new TiXmlText("������");
        TiXmlText *AgeContent = new TiXmlText("22");
        NameElement->LinkEndChild(NameContent);
        AgeElement->LinkEndChild(AgeContent);

        string fullPath = "D:\\"+szFileName;
        myDocument->SaveFile(fullPath.c_str());//���浽�ļ�
    }
    catch (string& e)
    {
        return false;
    }
    return true;
}

bool ReadXmlFile(string& szFileName)
{//��ȡXml�ļ���������
    try
    {
        string fullPath = "D:\\"+szFileName;
        
		//����һ��XML���ĵ�����
        TiXmlDocument *myDocument = new TiXmlDocument(fullPath.c_str());
        myDocument->LoadFile();
        //��ø�Ԫ�أ���Persons��
        TiXmlElement *RootElement = myDocument->RootElement();
        //�����Ԫ�����ƣ������Persons��
        cout << RootElement->Value() << endl;
        //��õ�һ��Person�ڵ㡣
        TiXmlElement *FirstPerson = RootElement->FirstChildElement();
        //��õ�һ��Person��name�ڵ��age�ڵ��ID���ԡ�
        TiXmlElement *NameElement = FirstPerson->FirstChildElement();
        TiXmlElement *AgeElement = NameElement->NextSiblingElement();
        TiXmlAttribute *IDAttribute = FirstPerson->FirstAttribute();
        //�����һ��Person��name���ݣ��������ǣ�age���ݣ�����ID���ԣ�����
        cout << NameElement->FirstChild()->Value() << endl;
        cout << AgeElement->FirstChild()->Value() << endl;
        cout << IDAttribute->Value()<< endl;
    }
    catch (string& e)
    {
        return false;
    }
    return true;
}

//-----------------------------------------------------
bool ReadXmlFile_unattend(string& szFileName)
{//��ȡXml�ļ���������
    try
    {
        string fullPath = "D:\\"+szFileName;
        
		//����һ��XML���ĵ�����
        TiXmlDocument *myDocument = new TiXmlDocument(fullPath.c_str());
        myDocument->LoadFile();
        //��ø�Ԫ�أ���Persons��
        TiXmlElement *RootElement = myDocument->RootElement();
        //�����Ԫ�����ƣ������Persons��
        cout << RootElement->Value() << endl;
        //��õ�һ��Person�ڵ㡣
        TiXmlElement *FirstSettings = RootElement->FirstChildElement();
        //��õ�һ��Person��name�ڵ��age�ڵ��ID���ԡ�
        TiXmlElement *Component = FirstSettings->FirstChildElement();
        TiXmlElement *ComputerName = Component->FirstChildElement();
		//�����һ��Person��name���ݣ��������ǣ�age���ݣ�����ID���ԣ�����
        cout << Component->FirstChild()->Value() << endl;
        cout << ComputerName->FirstChild()->Value() << endl;

        ComputerName->FirstChild()->SetValue("asdf");

		myDocument->SaveFile(fullPath.c_str());//���浽�ļ�

        cout << ComputerName->FirstChild()->Value() << endl;
    }
    catch (string& e)
    {
        return false;
    }
    return true;
}
//----------------------------------------------------------------

int main()
{
    string fileName = "unattend.xml";
    ReadXmlFile_unattend(fileName);
	//CreateXmlFile(fileName);
    //ReadXmlFile(fileName);

	return 0;
}