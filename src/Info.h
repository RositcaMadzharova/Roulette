/*
 * Info.h
 *
 *  Created on: 5.07.2017 ã.
 *      Author: Viktor
 */

#ifndef INFO_H_
#define INFO_H_

class Info
{
public:
	Info();
	virtual ~Info();

	friend void ShowInfo(Info*);
};

#endif /* INFO_H_ */
