// JNIDemo.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "JNIDemo.h"
#include "jni.h"
#include "jni_md.h"
#include<iostream>
#include "com_jni_demo_JNIDemo.h"

// 这是导出变量的一个示例
JNIDEMO_API int nJNIDemo=0;

// 这是导出函数的一个示例。
JNIDEMO_API int fnJNIDemo(void)
{
	return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 JNIDemo.h
CJNIDemo::CJNIDemo()
{
	return;
}

JNIEXPORT void JNICALL Java_com_jni_demo_JNIDemo_sayHello
	(JNIEnv * env, jobject obj)
{
	/// 获得obj 中对象的class 对象
	/// GetObjectClass是通过传入jni中的一个java的引用来获取该引用的类型。
	jclass clazz = env->GetObjectClass(obj);
	// 获取Java 中的number 字段的id （最后一个参数是number 的签名）
	jfieldID id_number = env->GetFieldID(clazz,"number","I");
	//获取number 的值
	jint number = env->GetIntField(obj,id_number);
	std::cout<<number <<std::endl;
	std::cout<<"helloworld"<<std::endl;
	env->SetIntField(obj,id_number,100L);
	/// 比较 a b 大小
	
	jmethodID max = env->GetMethodID(clazz,"max","(DD)D");
	jdouble doubles = env->CallDoubleMethod(obj,max,1.2,3.0);
	std::cout <<" max is:"<<doubles<<std::endl;
}
