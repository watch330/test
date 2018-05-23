package com.main;

public class StaticInitBlock {

	public static void main(String[] args) {
		System.out.println("main()");
		Tools2.t1.f(4);
	}
	static Tools2 ts = new Tools2(); 

}

class Tools2 {
	static Tool2 t1 = new Tool2(1);
	static {
		System.out.println("进入静态初始化块");
		t1 = new Tool2(11);
		t3 = new Tool2(33);
		t2 = new Tool2(22);
		System.out.println("退出静态初始化块");

	}
	static Tool2 t2 = new Tool2(2);

	Tools2() {
		System.out.println("Tools()");
	}

	static Tool2 t3 = new Tool2(3);
}

class Tool2 {
	Tool2(int i) {
		System.out.println("Tool2(" + i + ")");
	}

	void f(int i) {
		System.out.println("f(" + i + ")");
	}
}
