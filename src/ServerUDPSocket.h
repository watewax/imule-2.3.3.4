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

#ifndef SERVERUDPSOCKET_H
#define SERVERUDPSOCKET_H

#include "MuleUDPSocket.h"

#include <memory>

class CPacket;
class CServer;
class CMemFile;


class CServerUDPSocket : public CMuleUDPSocket
{
public:
        CServerUDPSocket(wxString destKeyName, const CProxyData* ProxyData = NULL);

	void	SendPacket(CPacket* packet, CServer* host, bool delPacket, bool rawpacket, uint16 port_offset);
        void	OnHostnameResolved(const CI2PAddress & dest);
        virtual void OnReceiveError(int errorCode, const CI2PAddress & dest);

private:
        void	OnPacketReceived(const CI2PAddress & dest, uint8_t* buffer, size_t length);
        void	ProcessPacket(CMemFile& packet, uint8 opcode, const CI2PAddress & dest);
	void	SendQueue();

	struct ServerUDPPacket {
                std::unique_ptr<CPacket>	packet;
                CI2PAddress		dest;
		wxString	addr;
	};

	typedef std::list<ServerUDPPacket> PacketList;
	PacketList m_queue;
};

#endif // SERVERUDPSOCKET_H
// File_checked_for_headers
