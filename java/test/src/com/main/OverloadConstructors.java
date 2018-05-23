/*
 	构造方法重载
*/
package com.main;

public class OverloadConstructors{
    public static void main(String[] args) {
    	Cat cat1 = new Cat();
    	System.out.println("Cat1 age:"+ cat1.age+"\tweight:"+cat1.weight);
    	Cat cat2 = new Cat(5,10);
    	System.out.println("Cat2 age:"+ cat2.age+"\tweight:"+cat2.weight);
    }
} 
class Cat {
	int age;
	int weight;
	
	Cat() {
		age = 2;
		weight = 5;
		System.out.println("in Cat()");
	}
	
	Cat(int itsAge, int itsWeight) {
		age = itsAge;
		weight = itsWeight;
		System.out.println("in Cat(int itsAge, int itsWeight)");
	}
}