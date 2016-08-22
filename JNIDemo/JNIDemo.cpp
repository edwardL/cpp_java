// JNIDemo.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "JNIDemo.h"
#include "jni.h"
#include "jni_md.h"
#include<iostream>
#include "com_jni_demo_JNIDemo.h"

// ���ǵ���������һ��ʾ��
JNIDEMO_API int nJNIDemo=0;

// ���ǵ���������һ��ʾ����
JNIDEMO_API int fnJNIDemo(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� JNIDemo.h
CJNIDemo::CJNIDemo()
{
	return;
}

JNIEXPORT void JNICALL Java_com_jni_demo_JNIDemo_sayHello
	(JNIEnv * env, jobject obj)
{
	/// ���obj �ж����class ����
	/// GetObjectClass��ͨ������jni�е�һ��java����������ȡ�����õ����͡�
	jclass clazz = env->GetObjectClass(obj);
	// ��ȡJava �е�number �ֶε�id �����һ��������number ��ǩ����
	jfieldID id_number = env->GetFieldID(clazz,"number","I");
	//��ȡnumber ��ֵ
	jint number = env->GetIntField(obj,id_number);
	std::cout<<number <<std::endl;
	std::cout<<"helloworld"<<std::endl;
	env->SetIntField(obj,id_number,100L);
	/// �Ƚ� a b ��С
	
	jmethodID max = env->GetMethodID(clazz,"max","(DD)D");
	jdouble doubles = env->CallDoubleMethod(obj,max,1.2,3.0);
	std::cout <<" max is:"<<doubles<<std::endl;
}
