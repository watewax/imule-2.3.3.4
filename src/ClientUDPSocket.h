//
// This file is part of the aMule Project.
//
// Copyright (c) 2003-2011 aMule Team ( admin@amule.org / http://www.amule.org )
// Copyright (c) 2002-2011 Merkur ( devs@emule-project.net / http://www.emule-project.net )
//
// Any parts of this program derived from the xMule, lMule or eMule project,
// or contributed by third-party developers are copyrighted by their
// respective authors.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA
//

#ifndef CLIENTUDPSOCKET_H
#define CLIENTUDPSOCKET_H

#include "MuleUDPSocket.h"

class CClientUDPSocket : public CMuleUDPSocket
{
public:
        CClientUDPSocket(wxString privKey, const CProxyData *ProxyData = NULL);

protected:
	void	OnReceive(int errorCode);

private:
        void	OnPacketReceived(const CI2PAddress & addr, byte* buffer, size_t length);
        void	ProcessPacket(byte* packet, int16 size, int8 opcode, const CI2PAddress & dest);
};

#endif // CLIENTUDPSOCKET_H
// File_checked_for_headers
