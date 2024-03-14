#include <gtest/gtest.h>
#include <QApplication>
#include "NeuroPanel.hpp"

class NeuroPanelTest : public NeuroPanel {
    public:
        NeuroPanelTest(QString name, QWidget* parent = nullptr) : NeuroPanel(name, parent) {}
        virtual ~NeuroPanelTest() {}
        virtual bool setup(const rosneuro_msgs::NeuroFrame& frame) { return true; }
        virtual void reset(void) {}
        virtual void update(const rosneuro_msgs::NeuroFrame& frame) {}
        virtual void draw(void) {}
};

class NeuroPanelTestSuite : public ::testing::Test {
public:
    NeuroPanelTestSuite() {}
    ~NeuroPanelTestSuite() {}
    void SetUp() {
        name = "TestNeuroPanel";
        parent = new QWidget();
        neuroPanel = new NeuroPanelTest(name, parent);
    }
    NeuroPanelTest* neuroPanel;
    QString name;
    QWidget* parent;
};

TEST_F(NeuroPanelTestSuite, TestSetName) {
    ASSERT_EQ(neuroPanel->name(), "TestNeuroPanel");
    neuroPanel->setName("TestNeuroPanel2");
    ASSERT_EQ(neuroPanel->name(), "TestNeuroPanel2");
    neuroPanel->setDataType(DataType::EEG);
    ASSERT_EQ(neuroPanel->getDataType(), DataType::EEG);
    ASSERT_EQ(neuroPanel->isset(), false);
}

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}