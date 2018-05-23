package watch330.firstOOP.calculator;

import watch330.firstOOP.uility.AreaCalculator;
import watch330.firstOOP.uility.Calculate;

public class CircleCalculator extends AreaCalculator implements Calculate {

	private double radius = 0.0D;
	
	private String type = "Բ";

	private void setRadius() {
		radius = Double.parseDouble(input.next());
	}

	// ʵ���Խӿ�Calculate
	@Override
	public void setParameter() {
		System.out.println("������Բ�İ뾶(��):");
		setRadius();
	}

	@Override
	public void showInfo() {
		if (checkInfo()) {
			System.out.println(type);
			System.out.println("Բ�İ뾶(��):" + radius);
		} else {
			System.out.println("���ݴ���,��������!");
			setParameter();
			while (!checkInfo()) {
				System.out.println("���ݴ���,��������!");
				setParameter();
			}
			System.out.println("Բ�İ뾶(��):" + radius);
		}

	}

	@Override
	public void getArea() {
		calculateArea();
		System.out.println("Բ�����(ƽ����):" + area);
	}
	
	//�����Գ�����AreaCalculator
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
