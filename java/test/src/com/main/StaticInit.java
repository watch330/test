/*
	���е����ݳ�Ա����ִ�й��췽��ǰ�ȳ�ʼ��,
	�Ⱦ�̬������˳��,����ͨ�İ�˳��,
	����췽��
*/
package com.main;

public class StaticInit {

	public static void main(String[] args) {
		System.out.println("Creating new Tools in main()");
		new Tools2();
		
		System.out.println("Creating new Tools in main()");
		new Tools2();
	}

}
class Tools1{
	Tool2 t1 = new Tool2(1);
	static Tool2 t2 = new Tool2(2);
	Tools1() {
		System.out.println("Tools()");
		t4 = new Tool2(44);
	}
	static Tool2 t3 = new Tool2(3);
	Tool2 t4 = new Tool2(4);
}
class Tool1 {
	Tool1(int i) {
		System.out.println("Tool("+i+")");
	}
}
