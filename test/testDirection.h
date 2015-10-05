#ifndef TESTDIRECTION_H
#define TESTDIRECTION_H

#include "autotest.h"
#include <QTest>
#include "direction.h"
#include <QDebug>

/**
 * @author amreo
 * @brief The TestDirection class
 * @version 1.0
 * @since 1.0
 */
class TestDirection : public QObject
{
		Q_OBJECT

	private slots:

		void common_data() {
			QTest::addColumn<int>("coeX");
			QTest::addColumn<int>("coeY");
			QTest::addColumn<int>("fixedCoeX");
			QTest::addColumn<int>("fixedCoeY");

			QTest::newRow("coe -1 -1") << -1 << -1 << -1 << -1;
			QTest::newRow("coe  0 -1") <<  0 << -1 <<  0 << -1;
			QTest::newRow("coe  1 -1") <<  1 << -1 <<  1 << -1;
			QTest::newRow("coe -1  0") << -1 <<  0 << -1 <<  0;
			QTest::newRow("coe  0  0") <<  0 <<  0 <<  0 <<  0;
			QTest::newRow("coe  1  0") <<  1 <<  0 <<  1 <<  0;
			QTest::newRow("coe -1  1") << -1 <<  1 << -1 <<  1;
			QTest::newRow("coe  0  1") <<  0 <<  1 <<  0 <<  1;
			QTest::newRow("coe  1  1") <<  1 <<  1 <<  1 <<  1;

			QTest::newRow("coe -2 -2") << -2 << -2 << -1 << -1;
			QTest::newRow("coe  0 -2") <<  0 << -2 <<  0 << -1;
			QTest::newRow("coe  2 -2") <<  2 << -2 <<  1 << -1;
			QTest::newRow("coe -2  0") << -2 <<  0 << -1 <<  0;
			QTest::newRow("coe  0  0") <<  0 <<  0 <<  0 <<  0;
			QTest::newRow("coe  2  0") <<  2 <<  0 <<  1 <<  0;
			QTest::newRow("coe -2  2") << -2 <<  2 << -1 <<  1;
			QTest::newRow("coe  0  2") <<  0 <<  2 <<  0 <<  1;
			QTest::newRow("coe  2  2") <<  2 <<  2 <<  1 <<  1;
		}

		void costructor1_data() {
			common_data();
		}

		void costructor1() {
			QFETCH(int, coeX);
			QFETCH(int, coeY);
			QFETCH(int, fixedCoeX);
			QFETCH(int, fixedCoeY);
			Direction dir (coeX, coeY);
			QVERIFY(dir.getCoefficientX() == fixedCoeX);
			QVERIFY(dir.getCoefficientY() == fixedCoeY);
		}
};


#endif // TESTDIRECTION_H
