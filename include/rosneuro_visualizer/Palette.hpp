#ifndef ROSNEURO_VISUALIZER_PALETTE_HPP
#define ROSNEURO_VISUALIZER_PALETTE_HPP

#include <vector>
#include <QColor>

class Palette {
	public:
		Palette(void);
		~Palette(void);

		void add(QColor color);

		void next(void);
		void previous(void);
		QColor get(void);
		void reset(void);

	private:
		std::vector<QColor> palette_;
		int	index_ = 0;
};

#endif
