// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#ifndef DJINNI_GENERATED_NJSGULDENUNIFIEDBACKEND_HPP
#define DJINNI_GENERATED_NJSGULDENUNIFIEDBACKEND_HPP


#include "NJSGuldenMonitorListener.hpp"
#include "NJSGuldenUnifiedFrontend.hpp"
#include "address_record.hpp"
#include "block_info_record.hpp"
#include "input_record.hpp"
#include "legacy_wallet_result.hpp"
#include "monitor_record.hpp"
#include "mutation_record.hpp"
#include "output_record.hpp"
#include "payment_result_status.hpp"
#include "peer_record.hpp"
#include "qr_code_record.hpp"
#include "transaction_record.hpp"
#include "uri_recipient.hpp"
#include "uri_record.hpp"
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include <nan.h>
#include <node.h>
#include <gulden_unified_backend.hpp>

using namespace v8;
using namespace node;
using namespace std;

class NJSGuldenUnifiedBackend final {
public:

    static void Initialize(Local<Object> target);
    NJSGuldenUnifiedBackend() = delete;

    static Local<Object> wrap(const std::shared_ptr<::GuldenUnifiedBackend> &object);
    static Nan::Persistent<ObjectTemplate> GuldenUnifiedBackend_prototype;

private:
    /** Get the build information (ie. commit id and status) */
    static NAN_METHOD(BuildInfo);

    /**
     * Start the library
     * extraArgs - any additional commandline arguments as passed to GuldenD
     * NB!!! This call blocks until the library is terminated, it is the callers responsibility to place it inside a thread or similar.
     * If you are in an environment where this is not possible (node.js for example use InitUnityLibThreaded instead which places it in a thread on your behalf)
     */
    static NAN_METHOD(InitUnityLib);

    /** Threaded implementation of InitUnityLib */
    static NAN_METHOD(InitUnityLibThreaded);

    /** Create the wallet - this should only be called after receiving a `notifyInit...` signal from InitUnityLib */
    static NAN_METHOD(InitWalletFromRecoveryPhrase);

    /** Continue creating wallet that was previously erased using EraseWalletSeedsAndAccounts */
    static NAN_METHOD(ContinueWalletFromRecoveryPhrase);

    /** Create the wallet - this should only be called after receiving a `notifyInit...` signal from InitUnityLib */
    static NAN_METHOD(InitWalletLinkedFromURI);

    /** Continue creating wallet that was previously erased using EraseWalletSeedsAndAccounts */
    static NAN_METHOD(ContinueWalletLinkedFromURI);

    /** Create the wallet - this should only be called after receiving a `notifyInit...` signal from InitUnityLib */
    static NAN_METHOD(InitWalletFromAndroidLegacyProtoWallet);

    /** Check if a file is a valid legacy proto wallet */
    static NAN_METHOD(isValidAndroidLegacyProtoWallet);

    /** Check link URI for validity */
    static NAN_METHOD(IsValidLinkURI);

    /** Replace the existing wallet accounts with a new one from a linked URI - only after first emptying the wallet. */
    static NAN_METHOD(ReplaceWalletLinkedFromURI);

    /**
     * Erase the seeds and accounts of a wallet leaving an empty wallet (with things like the address book intact)
     * After calling this it will be necessary to create a new linked account or recovery phrase account again.
     * NB! This will empty a wallet regardless of whether it has funds in it or not and makes no provisions to check for this - it is the callers responsibility to ensure that erasing the wallet is safe to do in this regard.
     */
    static NAN_METHOD(EraseWalletSeedsAndAccounts);

    /**
     * Check recovery phrase for (syntactic) validity
     * Considered valid if the contained mnemonic is valid and the birth-number is either absent or passes Base-10 checksum
     */
    static NAN_METHOD(IsValidRecoveryPhrase);

    /** Generate a new recovery mnemonic */
    static NAN_METHOD(GenerateRecoveryMnemonic);

    /** Compute recovery phrase with birth number */
    static NAN_METHOD(ComposeRecoveryPhrase);

    /** Stop the library */
    static NAN_METHOD(TerminateUnityLib);

    /** Generate a QR code for a string, QR code will be as close to width_hint as possible when applying simple scaling. */
    static NAN_METHOD(QRImageFromString);

    /** Get a receive address from the wallet */
    static NAN_METHOD(GetReceiveAddress);

    /** Get the recovery phrase for the wallet */
    static NAN_METHOD(GetRecoveryPhrase);

    /** Check if the wallet is using a mnemonic seed ie. recovery phrase (else it is a linked wallet) */
    static NAN_METHOD(IsMnemonicWallet);

    /** Check if the phrase mnemonic is a correct one for the wallet (phrase can be with or without birth time) */
    static NAN_METHOD(IsMnemonicCorrect);

    /** Unlock wallet */
    static NAN_METHOD(UnlockWallet);

    /** Forcefully lock wallet again */
    static NAN_METHOD(LockWallet);

    /** Change the waller password */
    static NAN_METHOD(ChangePassword);

    /** Check if the wallet has any transactions that are still pending confirmation, to be used to determine if e.g. it is safe to perform a link or whether we should wait. */
    static NAN_METHOD(HaveUnconfirmedFunds);

    /** Check current wallet balance (including unconfirmed funds) */
    static NAN_METHOD(GetBalance);

    /** Rescan blockchain for wallet transactions */
    static NAN_METHOD(DoRescan);

    /** Check if text/address is something we are capable of sending money too */
    static NAN_METHOD(IsValidRecipient);

    /** Compute the fee required to send amount to given recipient */
    static NAN_METHOD(feeForRecipient);

    /** Attempt to pay a recipient, will throw on failure with description */
    static NAN_METHOD(performPaymentToRecipient);

    /** Get list of all transactions wallet has been involved in */
    static NAN_METHOD(getTransactionHistory);

    /**
     * Get the wallet transaction for the hash
     * Will throw if not found
     */
    static NAN_METHOD(getTransaction);

    /** Get list of wallet mutations */
    static NAN_METHOD(getMutationHistory);

    /** Get list of all address book entries */
    static NAN_METHOD(getAddressBookRecords);

    /** Add a record to the address book */
    static NAN_METHOD(addAddressBookRecord);

    /** Delete a record from the address book */
    static NAN_METHOD(deleteAddressBookRecord);

    /** Interim persist and prune of state. Use at key moments like app backgrounding. */
    static NAN_METHOD(PersistAndPruneForSPV);

    /**
     * Reset progress notification. In cases where there has been no progress for a long time, but the process
     * is still running the progress can be reset and will represent work to be done from this reset onwards.
     * For example when the process is in the background on iOS for a long long time (but has not been terminated
     * by the OS) this might make more sense then to continue the progress from where it was a day or more ago.
     */
    static NAN_METHOD(ResetUnifiedProgress);

    /** Get connected peer info */
    static NAN_METHOD(getPeers);

    /** Get info of last blocks (at most 32) in SPV chain */
    static NAN_METHOD(getLastSPVBlockInfos);

    static NAN_METHOD(getUnifiedProgress);

    static NAN_METHOD(getMonitoringStats);

    static NAN_METHOD(RegisterMonitorListener);

    static NAN_METHOD(UnregisterMonitorListener);

    static NAN_METHOD(New);

    static NAN_METHOD(isNull);
};
#endif //DJINNI_GENERATED_NJSGULDENUNIFIEDBACKEND_HPP
