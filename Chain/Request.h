
#ifndef _REQUEST_H
#define _REQUEST_H

class Request {

public:
	enum class RequestType {

		

	};

protected:
	RequestType requestType;

public:
	Request(RequestType requestType);
	virtual ~Request() = 0;

	inline RequestType getRequestType() const { return this->requestType; }

};

#endif //_REQUEST_H