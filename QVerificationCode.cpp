#include "QVerificationCode.h"

QVerificationCode::~QVerificationCode()
{
}
void QVerificationCode::paintEvent(QPaintEvent* event)
{
	code.clear();
	QPainter painter(this);
	QPen pen;
	//»­µã
	for (int i = 0; i < pointNumber; i++) {
		pen = QPen(QColor(rand()%256, rand()%256, rand()%256));
		painter.setPen(pen);
		painter.drawPoint(rand()%150, rand()%50);
	}
	//»­Ïß
	for (int i = 0; i < lineNumber; i++) {
		painter.drawLine(rand()%150, rand()%50,
			rand()%150, rand()%50);
	}
	//Ëæ»úÊý×Ö
	for (int i = 0; i < codeNumber; i++) {
		int num = rand()%3;
		if (num == 0)//Êý×Ö
			code += QString::number(rand()%10);
		else if (num == 1) {//´óÐ´×ÖÄ¸
			int temp = 'A';
			code += static_cast<QChar>(temp + rand()%26);
		}
		else if (num == 2) { //Ð¡Ð´×ÖÄ¸
			int temp = 'a';
			code += static_cast<QChar>(temp + rand()%26);
		}
	}
	pen = QPen(QColor(255, 0, 0, 100));
	QFont font("¿¬Ìå", 25, QFont::Bold, true);
	painter.setFont(font);
	painter.setPen(pen);
	//»æ»­×Ö
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
