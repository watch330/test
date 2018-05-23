package watch330.firstOOP.calculator;

import watch330.firstOOP.uility.AreaCalculator;
import watch330.firstOOP.uility.Calculate;

public class TriangleCalculator extends AreaCalculator implements Calculate {

	private double[] line = new double[3];
	private String[] num;
	private double p = 0.0D;
	private String type = "������";

	private void setLine() {
		num = input.nextLine().split(" ");
		for (int i = 0; i < line.length; i++) {
			line[i] = Double.parseDouble(num[i]);
		}
	}

	// ʵ���Խӿ�Calculate
	@Override
	public void setParameter() {
		System.out.println("�����������ε�������(��):");
		setLine();
	}

	@Override
	public void showInfo() {
		if (checkInfo()) {
			System.out.println(type);
			System.out.println("�����ε�������(��):" + line[0] + " " + line[1] + " " + line[2]);
		} else {
			System.out.println("���ݴ���,��������!");
			setParameter();
			while (!checkInfo()) {
				System.out.println("���ݴ���,��������!");
				setParameter();
			}
			System.out.println("�����ε�������(��):" + line[0] + " " + line[1] + " " + line[2]);
		}
	}

	@Override
	public void getArea() {
		calculateArea();
		System.out.println("�����ε����(ƽ����):" + area);
	}

	// �����Գ�����AreaCalculator
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
