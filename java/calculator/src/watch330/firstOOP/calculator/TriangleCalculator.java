package watch330.firstOOP.calculator;

import watch330.firstOOP.uility.AreaCalculator;
import watch330.firstOOP.uility.Calculate;

public class TriangleCalculator extends AreaCalculator implements Calculate {

	private double[] line = new double[3];
	private String[] num;
	private double p = 0.0D;
	private String type = "三角形";

	private void setLine() {
		num = input.nextLine().split(" ");
		for (int i = 0; i < line.length; i++) {
			line[i] = Double.parseDouble(num[i]);
		}
	}

	// 实现自接口Calculate
	@Override
	public void setParameter() {
		System.out.println("请输入三角形的三条边(米):");
		setLine();
	}

	@Override
	public void showInfo() {
		if (checkInfo()) {
			System.out.println(type);
			System.out.println("三角形的三条边(米):" + line[0] + " " + line[1] + " " + line[2]);
		} else {
			System.out.println("数据错误,重新输入!");
			setParameter();
			while (!checkInfo()) {
				System.out.println("数据错误,重新输入!");
				setParameter();
			}
			System.out.println("三角形的三条边(米):" + line[0] + " " + line[1] + " " + line[2]);
		}
	}

	@Override
	public void getArea() {
		calculateArea();
		System.out.println("三角形的面积(平方米):" + area);
	}

	// 重载自抽象父类AreaCalculator
	@Override
	protected boolean checkInfo() {
		if ((line[0] + line[1]) <= line[2] || (line[0] + line[2]) <= line[1] || (line[1] + line[2]) <= line[0]) {
			return false;
		} else
			return true;
	}

	@Override
	protected void calculateArea() {
		
		p = (line[0]+line[1]+line[2])/2.0;
		area =Math.sqrt(p*(p-line[0])*(p-line[1])*(p-line[2]));
	}

}
