#include "QVerificationCode.h"

QVerificationCode::~QVerificationCode()
{
}
void QVerificationCode::paintEvent(QPaintEvent* event)
{
	code.clear();
	QPainter painter(this);
	QPen pen;
	//����
	for (int i = 0; i < pointNumber; i++) {
		pen = QPen(QColor(rand()%256, rand()%256, rand()%256));
		painter.setPen(pen);
		painter.drawPoint(rand()%150, rand()%50);
	}
	//����
	for (int i = 0; i < lineNumber; i++) {
		painter.drawLine(rand()%150, rand()%50,
			rand()%150, rand()%50);
	}
	//�������
	for (int i = 0; i < codeNumber; i++) {
		int num = rand()%3;
		if (num == 0)//����
			code += QString::number(rand()%10);
		else if (num == 1) {//��д��ĸ
			int temp = 'A';
			code += static_cast<QChar>(temp + rand()%26);
		}
		else if (num == 2) { //Сд��ĸ
			int temp = 'a';
			code += static_cast<QChar>(temp + rand()%26);
		}
	}
	pen = QPen(QColor(255, 0, 0, 100));
	QFont font("����", 25, QFont::Bold, true);
	painter.setFont(font);
	painter.setPen(pen);
	//�滭��
	for (int i = 0; i < codeNumber; i++)
		painter.drawText(10 + 30 * i, 5, 30, 40, Qt::AlignCenter, QString(code[i]));

}

void QVerificationCode::mousePressEvent(QMouseEvent* event)
{
	update();
}

QString QVerificationCode::getCode()
{
	return code;
}
