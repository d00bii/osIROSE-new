#include "ccharserver.h"
#include "ccharisc.h"
#include "ccharclient.h"
#include "epackettype.h"
#include "rosepackets.h"

using namespace RoseCommon;

CCharClient::CCharClient() : CRoseClient(), access_rights_(0) {
}

CCharClient::CCharClient(tcp::socket _sock)
    : CRoseClient(std::move(_sock)), access_rights_(0) {
}

bool CCharClient::HandlePacket(uint8_t* _buffer) {
  switch (CRosePacket::type(_buffer)) {
    case ePacketType::PAKCS_JOIN_SERVER_REQ:
      return JoinServerReply(getPacket<ePacketType::PAKCS_JOIN_SERVER_REQ>(_buffer));  // Allow client to connect
//    case ePacketType::PAKCS_CHAR_LIST_REQ:
//      return SendCharListReply(pak);  // SendCharList( pak );
//    case ePacketType::PAKCS_CREATE_CHAR_REQ:
//      return SendCharCreateReply(pak);
//    case ePacketType::PAKCS_DELETE_CHAR_REQ:
//      return SendCharDeleteReply(pak);
//    case ePacketType::PAKCS_SELECT_CHAR_REQ:
//      return SendCharSelectReply(pak);
    default:
      return CRoseClient::HandlePacket(_buffer);
  }
  return true;
}

bool CCharClient::OnReceived() { return CRoseClient::OnReceived(); }

bool CCharClient::JoinServerReply(std::unique_ptr<RoseCommon::CliJoinServerReq> P) {
  (void)P;
  logger_->trace("JoinServerReply\n");

  //uint32_t channelID = P->id(); 

  //ask the login server if this client actually logged in successfully and selected that channel

  auto packet = makePacket<ePacketType::PAKSC_JOIN_SERVER_REPLY>(SrvJoinServerReply::OK, std::time(nullptr));
  Send(*packet);

  return true;
}

bool CCharClient::SendCharListReply(CRosePacket* P) {
  (void)P;
  logger_->trace("CharListReply\n");

  return true;
}

bool CCharClient::SendCharCreateReply(CRosePacket* P) {
  (void)P;
  logger_->trace("CharCreateReply\n");

  return true;
}

bool CCharClient::SendCharDeleteReply(CRosePacket* P) {
	(void)P;
  logger_->trace("CharDeleteReply\n");
//  uint8_t charid = P->Get<uint8_t>( 0 );
//  bool _delete = P->Get<uint8_t>( 1 );
//
//  if( charid > 6 )
//    return false;
//
//  char name[17];
//  memset(name, 0, 17);
//  P->GetString(0, 16, name);
//  if(_delete)
//  {
//    // we need to delete the char
//  }

  return true;
}

bool CCharClient::SendCharSelectReply(CRosePacket* P) {
  (void)P;
  logger_->trace("CharSelectReply\n");

  return true;
}
