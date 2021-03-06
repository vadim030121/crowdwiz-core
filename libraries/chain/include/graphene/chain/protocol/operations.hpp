/*
 * Copyright (c) 2015 Cryptonomex, Inc., and contributors.
 *
 * The MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#pragma once
#include <graphene/chain/protocol/base.hpp>
#include <graphene/chain/protocol/account.hpp>
#include <graphene/chain/protocol/assert.hpp>
#include <graphene/chain/protocol/asset_ops.hpp>
#include <graphene/chain/protocol/balance.hpp>
#include <graphene/chain/protocol/custom.hpp>
#include <graphene/chain/protocol/committee_member.hpp>
#include <graphene/chain/protocol/confidential.hpp>
#include <graphene/chain/protocol/fba.hpp>
#include <graphene/chain/protocol/market.hpp>
#include <graphene/chain/protocol/proposal.hpp>
#include <graphene/chain/protocol/transfer.hpp>
#include <graphene/chain/protocol/vesting.hpp>
#include <graphene/chain/protocol/withdraw_permission.hpp>
#include <graphene/chain/protocol/witness.hpp>
#include <graphene/chain/protocol/worker.hpp>
#include <graphene/chain/protocol/gamezone.hpp>
#include <graphene/chain/protocol/send_message.hpp>
#include <graphene/chain/protocol/exchange.hpp>
#include <graphene/chain/protocol/financial.hpp>
#include <graphene/chain/protocol/poc.hpp>

namespace graphene { namespace chain {

   /**
    * @ingroup operations
    *
    * Defines the set of valid operations as a discriminated union type.
    */
   typedef fc::static_variant<
            transfer_operation,
            limit_order_create_operation,
            limit_order_cancel_operation,
            call_order_update_operation,
            fill_order_operation,           // VIRTUAL
            account_create_operation,
            account_update_operation,
            account_whitelist_operation,
            account_upgrade_operation,
            account_transfer_operation,
            asset_create_operation,
            asset_update_operation,
            asset_update_bitasset_operation,
            asset_update_feed_producers_operation,
            asset_issue_operation,
            asset_reserve_operation,
            asset_fund_fee_pool_operation,
            asset_settle_operation,
            asset_global_settle_operation,
            asset_publish_feed_operation,
            witness_create_operation,
            witness_update_operation,
            proposal_create_operation,
            proposal_update_operation,
            proposal_delete_operation,
            withdraw_permission_create_operation,
            withdraw_permission_update_operation,
            withdraw_permission_claim_operation,
            withdraw_permission_delete_operation,
            committee_member_create_operation,
            committee_member_update_operation,
            committee_member_update_global_parameters_operation,
            vesting_balance_create_operation,
            vesting_balance_withdraw_operation,
            worker_create_operation,
            custom_operation,
            assert_operation,
            balance_claim_operation,
            override_transfer_operation,
            transfer_to_blind_operation,
            blind_transfer_operation,
            transfer_from_blind_operation,
            asset_settle_cancel_operation,  // VIRTUAL
            asset_claim_fees_operation,
            fba_distribute_operation,       // VIRTUAL
            bid_collateral_operation,
            execute_bid_operation,          // VIRTUAL
            asset_claim_pool_operation,
            asset_update_issuer_operation,
            account_status_upgrade_operation,
            flipcoin_bet_operation,  //GAMEZONE
            flipcoin_call_operation,  //GAMEZONE
            flipcoin_win_operation,  //VOP
            flipcoin_cancel_operation,  //VOP
            flipcoin_loose_operation,  //VOP
            lottery_goods_create_lot_operation,  // GAMEZONE
            lottery_goods_buy_ticket_operation,  // GAMEZONE
            lottery_goods_send_contacts_operation,  // GAMEZONE
            lottery_goods_confirm_delivery_operation,  // GAMEZONE
            lottery_goods_win_operation,  // GAMEZONE, VIRTUAL
            lottery_goods_loose_operation,  // GAMEZONE, VIRTUAL
            send_message_operation,
            matrix_open_room_operation,
            matrix_room_closed_operation, // GAMEZONE, VIRTUAL
            matrix_cell_filled_operation, // GAMEZONE, VIRTUAL
            create_p2p_adv_operation, // EXCHANGE
            edit_p2p_adv_operation, // EXCHANGE
            clear_p2p_adv_black_list_operation, // EXCHANGE
            remove_from_p2p_adv_black_list_operation, // EXCHANGE
            create_p2p_order_operation, // EXCHANGE
            cancel_p2p_order_operation, // EXCHANGE
            autocancel_p2p_order_operation, // EXCHANGE, VIRTUAL
            autorefund_p2p_order_operation, // EXCHANGE, VIRTUAL
            call_p2p_order_operation, // EXCHANGE
            payment_p2p_order_operation, // EXCHANGE
            release_p2p_order_operation, // EXCHANGE
            open_p2p_dispute_operation, // EXCHANGE
            reply_p2p_dispute_operation, // EXCHANGE
            resolve_p2p_dispute_operation, // EXCHANGE
            lottery_goods_refund_operation,  // GAMEZONE, VIRTUAL
            credit_system_get_operation, //FINANCIAL
            credit_total_repay_operation, //FINANCIAL, VIRTUAL
            credit_repay_operation, //FINANCIAL
            credit_offer_create_operation, //FINANCIAL
            credit_offer_cancel_operation, //FINANCIAL
            credit_offer_fill_operation, //FINANCIAL
            pledge_offer_give_create_operation, //FINANCIAL
            pledge_offer_take_create_operation, //FINANCIAL
            pledge_offer_cancel_operation, //FINANCIAL
            pledge_offer_fill_operation, //FINANCIAL
            pledge_offer_repay_operation, //FINANCIAL
            pledge_offer_auto_repay_operation, //FINANCIAL, VIRTUAL
            committee_member_update_gamezone_parameters_operation,
            committee_member_update_staking_parameters_operation,
            poc_vote_operation, //PoC
            poc_stak_operation, //PoC
            poc_staking_referal_operation, //PoC, VIRTUAL
            exchange_silver_operation,//PoC
            buy_gcwd_operation,
            approved_transfer_create_operation,
            approved_transfer_approve_operation,
            approved_transfer_cancel_operation,
            approved_transfer_open_dispute_operation,
            approved_transfer_resolve_dispute_operation,
            mass_payment_operation,
            mass_payment_pay_operation
         > operation;

   /// @} // operations group

   /**
    *  Appends required authorites to the result vector.  The authorities appended are not the
    *  same as those returned by get_required_auth 
    *
    *  @return a set of required authorities for @ref op
    */
   void operation_get_required_authorities( const operation& op, 
                                            flat_set<account_id_type>& active,
                                            flat_set<account_id_type>& owner,
                                            vector<authority>&  other );

   void operation_validate( const operation& op );

   /**
    *  @brief necessary to support nested operations inside the proposal_create_operation
    */
   struct op_wrapper
   {
      public:
         op_wrapper(const operation& op = operation()):op(op){}
         operation op;
   };

} } // graphene::chain

FC_REFLECT_TYPENAME( graphene::chain::operation )
FC_REFLECT( graphene::chain::op_wrapper, (op) )
