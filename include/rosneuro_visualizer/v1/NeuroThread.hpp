#ifndef ROSNEURO_VISUALIZER_NEUROTHREAD_HPP
#define ROSNEURO_VISUALIZER_NEUROTHREAD_HPP

#include <QMutex>
#include <QThread>

class NeuroThread : public QThread {
	
	Q_OBJECT

	public:
		NeuroThread(QObject* parent = nullptr);
		virtual ~NeuroThread(void);

		void start_thread(void);
		void stop_thread(void);

	protected:
		virtual void run(void) = 0;

	protected:

		QMutex 	mutex_;
		bool 	restart_ = false;
		bool 	abort_   = false;

};

#endif
