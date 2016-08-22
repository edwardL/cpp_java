package com.jni.demo;

public class JNIDemo {
	// 定义个本地方法
	public native void sayHello();
	public int number = 0; ///定义一个属性
	
	public static void main(String[] args)
	{
		// 调用动态链接库
//		System.setProperty("java.library.path", "F:\\android_proj\\JNIDemo\\bin\\com\\jni\\demo" );
		System.loadLibrary("JNIDemo");
		JNIDemo jnidemo = new JNIDemo();
		jnidemo.sayHello();
		System.out.print(jnidemo.number);
	}
	
	public double max(double a,double b)
	{
		System.out.println("a=" + a + ",b=" + b);
		return a > b ? a : b;
	}
}
