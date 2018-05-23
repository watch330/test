package watch330.firstOOP.calculator;

import watch330.firstOOP.uility.AreaCalculator;
import watch330.firstOOP.uility.Calculate;

public class CircleCalculator extends AreaCalculator implements Calculate {

	private double radius = 0.0D;
	
	private String type = "圆";

	private void setRadius() {
		radius = Double.parseDouble(input.next());
	}

	// 实现自接口Calculate
	@Override
	public void setParameter() {
		System.out.println("请输入圆的半径(米):");
		setRadius();
	}

	@Override
	public void showInfo() {
		if (checkInfo()) {
			System.out.println(type);
			System.out.println("圆的半径(米):" + radius);
		} else {
			System.out.println("数据错误,重新输入!");
			setParameter();
			while (!checkInfo()) {
				System.out.println("数据错误,重新输入!");
				setParameter();
			}
			System.out.println("圆的半径(米):" + radius);
		}

	}

	@Override
	public void getArea() {
		calculateArea();
		System.out.println("圆的面积(平方米):" + area);
	}
	
	//重载自抽象父类AreaCalculator
	@Override
	protected boolean checkInfo() {
		if (radius <= 0) {
			return false;
		} else {
			return true;
		}
	}

	@Override
	protected void calculateArea() {
		area = Math.PI * radius * radius;

	}

}
