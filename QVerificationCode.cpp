#include "QVerificationCode.h"
QVerificationCode::QVerificationCode(QWidget* parent ) {

}
QVerificationCode::~QVerificationCode()
{
}
void QVerificationCode::paintEvent(QPaintEvent* event)
{
	code.clear();
	QPainter painter(this);
	QPen pen;
	//����
	QRandomGenerator rand ;
	for (int i = 0; i < pointNumber; i++) {
		pen = QPen(QColor(rand.bounded(1,256), rand.bounded(1,256), rand.bounded(1,256)));
		painter.setPen(pen);
		painter.drawPoint(rand.bounded(1, 150), rand.bounded(1, 50));
	}
	//����
	for (int i = 0; i < lineNumber; i++) {
		painter.drawLine(rand.bounded(1, 150), rand.bounded(1, 50),
			rand.bounded(1, 150), rand.bounded(1, 50));
	}
	//�������
	for (int i = 0; i < codeNumber; i++) {
		int num = rand.bounded(0, 3);
		if (num == 0)//����
			code += QString::number(rand.bounded(0, 10));
		else if (num == 1) {//��д��ĸ
			int temp = 'A';
			code += static_cast<QChar>(temp + rand.bounded(0, 26));
		}
		else if (num == 2) { //Сд��ĸ
			int temp = 'a';
			code += static_cast<QChar>(temp + rand.bounded(0, 26));
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
