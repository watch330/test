package watch_330.account.accountant;

import watch_330.account.uility.Function;

import java.util.Scanner;

import java.util.List;
import java.util.ArrayList;

import java.util.Date;
import java.text.SimpleDateFormat;

public class Account implements Function {

	private Scanner input = new Scanner(System.in);
	
	private List<String> list = new ArrayList<String>();
	private StringBuffer tempStr = new StringBuffer();
	
	private SimpleDateFormat df = new SimpleDateFormat("yyyy.MM.dd HH:mm");
	private int balance =0;

	@Override
	public void showDetails() {
		System.out.println("-------------------��ǰ��֧��ϸ��¼--------------------");
		System.out.println("��֧\t��֧���      �˻����   ˵ ��         ʱ ��");
		for (String string : list) {
			System.out.println(string);
		}
		System.out.println("--------------------------------------------------------");
		System.out.println("Enter�Է��ؽ���");
		input.nextLine();
	}

	@Override
	public void setIn() {
		int money;
		tempStr.append("����\t");
		System.out.println("����������:");
		money = input.nextInt();
		balance +=money;
		tempStr.append(String.valueOf(money)+"\t\t"+String.valueOf(balance)+"\t  ");
		System.out.println("��������˵��:");
		input.nextLine();
		tempStr.append(input.nextLine()+"\t"+df.format(new Date()));
		list.add(tempStr.toString());
		tempStr.delete(0, tempStr.length());
		
	}

	@Override
	public void setOut() {
		// TODO �Զ����ɵķ������
		int money;
		tempStr.append("֧��\t");
		System.out.println("����֧�����:");
		money = input.nextInt();
		balance -=money;
		tempStr.append(String.valueOf(money)+"\t\t"+String.valueOf(balance)+"\t  ");
		System.out.println("����֧��˵��:");
		input.nextLine();
		tempStr.append(input.nextLine()+"\t"+df.format(new Date()));
		list.add(tempStr.toString());
		tempStr.delete(0, tempStr.length());

	}

	@Override
	public void quit() {
		System.out.println("ȷ���Ƿ��˳�(1/0)");
		if(input.nextInt()==1) {
			System.exit(1);
		}
	}
	public boolean isListEmpty() {
		return list.isEmpty();
	}

}
