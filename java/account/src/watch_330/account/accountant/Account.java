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
		System.out.println("-------------------当前收支明细记录--------------------");
		System.out.println("收支\t收支金额      账户余额   说 明         时 间");
		for (String string : list) {
			System.out.println(string);
		}
		System.out.println("--------------------------------------------------------");
		System.out.println("Enter以返回界面");
		input.nextLine();
	}

	@Override
	public void setIn() {
		int money;
		tempStr.append("收入\t");
		System.out.println("本次收入金额:");
		money = input.nextInt();
		balance +=money;
		tempStr.append(String.valueOf(money)+"\t\t"+String.valueOf(balance)+"\t  ");
		System.out.println("本次收入说明:");
		input.nextLine();
		tempStr.append(input.nextLine()+"\t"+df.format(new Date()));
		list.add(tempStr.toString());
		tempStr.delete(0, tempStr.length());
		
	}

	@Override
	public void setOut() {
		// TODO 自动生成的方法存根
		int money;
		tempStr.append("支出\t");
		System.out.println("本次支出金额:");
		money = input.nextInt();
		balance -=money;
		tempStr.append(String.valueOf(money)+"\t\t"+String.valueOf(balance)+"\t  ");
		System.out.println("本次支出说明:");
		input.nextLine();
		tempStr.append(input.nextLine()+"\t"+df.format(new Date()));
		list.add(tempStr.toString());
		tempStr.delete(0, tempStr.length());

	}

	@Override
	public void quit() {
		System.out.println("确认是否退出(1/0)");
		if(input.nextInt()==1) {
			System.exit(1);
		}
	}
	public boolean isListEmpty() {
		return list.isEmpty();
	}

}
